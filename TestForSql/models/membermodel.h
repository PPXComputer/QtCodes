#ifndef MEMBERMODEL_H
#define MEMBERMODEL_H
#include <QDebug>
#include <QString>
#include <QtSql>
/*/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlTableModel>*/
// 拥有 一个 className 为 className+"_Member"
// 类型 分别为   Name : varchar  Type :varchar
// 应该在总表格中使用  每个文件都有一个总表格来进行使用 MemberModelCount
// toRefleshGlobal 设置 总表格相关的 数据 true添加 flase 删除
class MemberModel : public QSqlTableModel
{
    Q_OBJECT
    Q_PROPERTY(QString className READ getclassName WRITE setclassName NOTIFY classNameChanged)
public:
    enum class MemberRole { type = Qt::UserRole + 1, name };
    explicit MemberModel(QObject *parent = nullptr);
    MemberModel(const MemberModel &) = delete;
    ~MemberModel() override = default;

public:
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    //设置职责 即 对应的行号
    QHash<int, QByteArray> roleNames() const override;
    QString getclassName() const;
    void setclassName(QString className);
signals:
    void classNameChanged(const QString &name);
    void needToInitTbale(); // 在 表格被 删除 和  表格被重新创建 时 触发
    void needToResetClassName();
public slots:
    Q_INVOKABLE bool addMember(QString &type, QString &name);
    Q_INVOKABLE bool deleteMember(QString &name);
    Q_INVOKABLE bool dropTable();
    Q_INVOKABLE bool initTable();

private:
    QString className = "_Member";
    void initHeader();

    // true 添加 数据  false  删除 数据
    bool toRefleshGlobal(bool addOrDel = true);
};

#endif // MEMBERMODEL_H
