#ifndef MYMODEL_H
#define MYMODEL_H

#include <QModelIndex>
#include <QObject>
#include <qdebug.h>
#include <qsqldatabase.h>
#include <qsqlerror.h>
#include <qsqlquery.h>
#include <qsqlrecord.h>
#include <qsqltablemodel.h>
//每个文件一个只有一个 class.db
//此类作为 tableview的model使用 展示的是 function相关的数据
//表格数据为 Name Value  Args
class MyModel : public QSqlTableModel
{
    Q_OBJECT
    Q_PROPERTY(QString tableName READ getTableName WRITE setTableName NOTIFY tableNameChanged)
public:
    enum class MemberRole { type = Qt::UserRole + 1, name, access };
    enum class FunctionRole { values = Qt::UserRole + 1, name, args, access };
    enum class UsingRole { Function, Member };
    explicit MyModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    //设置职责 即 对应的行号
    virtual QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE void setTableName(QString name)
    {
        if (tableName != name) {
            tableName = std::move(name);
            emit tableNameChanged(tableName);
        }
    }
    Q_INVOKABLE QString getTableName() const { return this->tableName; }
signals:
    void tableNameChanged(QString name);
public slots:
    Q_INVOKABLE virtual bool dropTable();
    void initHeader(); //与tableNameChanged的槽函数

protected:
    bool initTable();
    QString tableName="";
};

#endif // MYMODEL_H
