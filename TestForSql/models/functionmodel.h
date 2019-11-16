#ifndef FUNCTIONMODEL_H
#define FUNCTIONMODEL_H
#include <QtDebug>
#include <QtSql>
// className_Function   表格为 Name :varchar Args :varchar Value: varchar
// 在 更新 总表格 为 Global database设置为 localPath
class FunctionModel : public QSqlTableModel
{
    Q_OBJECT
    Q_PROPERTY(QString className READ getClassName WRITE setClassName NOTIFY classNameChanged)
public:
    enum class FunctionRole { type = Qt::UserRole + 1, name };
    explicit FunctionModel(QObject *parent = nullptr);
    FunctionModel(const FunctionModel &) = delete;
    ~FunctionModel() override = default;

public:
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    //设置职责 即 对应的行号 initHeader设置每行的行名
    QHash<int, QByteArray> roleNames() const override;
    QString getClassName() const;
    void setClassName(QString className);
signals:
    void classNameChanged(const QString &name);
    void needToInitTbale(); // 在 表格被 删除 和  表格被重新创建 时 触发
    void needToResetClassName();
public slots:
    Q_INVOKABLE bool addFunction(const QString &name, const QString &args, const QString &values);
    Q_INVOKABLE bool deleteFunction(QString &name);
    Q_INVOKABLE bool dropTable();
    Q_INVOKABLE bool initTable();

private:
    QString className = "_Function";
    // true 添加 数据  false  删除 数据
    bool toRefleshGlobal(bool addOrDel = true);
    void initHeader();
};

#endif // FunctionModel_H
