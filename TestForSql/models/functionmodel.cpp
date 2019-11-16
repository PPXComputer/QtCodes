#include "functionmodel.h"

FunctionModel::FunctionModel(QObject *parent)
    : QSqlTableModel(parent, QSqlDatabase::addDatabase("SQLITE", "localPath"))
{
    initHeader();
    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
    connect(this,
            &FunctionModel::classNameChanged,
            this,
            &FunctionModel::initTable,
            Qt::QueuedConnection);
}

QVariant FunctionModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);
    if (role < Qt::UserRole) {
        value = QSqlTableModel::data(index, role);
    } else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlTableModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

bool FunctionModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool ret;
    if (role < Qt::UserRole) {
        ret = QSqlTableModel::setData(index, value, role);
    } else {
        int colIdx = role - Qt::UserRole - 1;

        ret = QSqlTableModel::setData(this->index(index.row(), colIdx), value, Qt::DisplayRole);
    }

    return ret;
}

QHash<int, QByteArray> FunctionModel::roleNames() const
{
    //设置为 UseRole使用的大量数据
    QHash<int, QByteArray> roleNames;
    for (int i = 0; i < record().count(); i++) {
        roleNames[Qt::UserRole + i + 1] = record().fieldName(i).toUtf8();
    }
    return roleNames;
}

QString FunctionModel::getClassName() const
{
    return className.left(className.indexOf("Function"));
}

void FunctionModel::setClassName(QString classofTable)
{
    if (classofTable.contains("_Function")) {
        emit needToResetClassName();
        return;
    }
    QString name = classofTable + "_Function";
    if (this->className == name) {
        className = std::move(name);
        emit classNameChanged(className);
    }
}

bool FunctionModel::addFunction(const QString &name, const QString &args, const QString &values)
{
    assert(database().isOpen());
    if (!database().tables().contains(this->className)) {
        return false;
    }
    auto query = this->query();
    query.prepare(QString(
        "insert into :table ( Name , Args ,Value ) values ( ':name' , ':args' , ':values' )"));
    query.bindValue(":table", this->className);
    query.bindValue(":name", name);
    query.bindValue(":args", args);
    query.bindValue(":values", values);
    return query.exec() && submitAll();
}

bool FunctionModel::deleteFunction(QString &name)
{
    assert(database().isOpen());
    if (!database().tables().contains(this->className)) {
        return false;
    }
    auto query = this->query();
    query.prepare(QString("delete  from :table where Name = ' :name '"));
    query.bindValue(":name", name);
    return query.exec() && submitAll();
}

bool FunctionModel::dropTable()
{
    assert(database().isOpen());
    if (!database().tables().contains(this->className)) {
        return false;
    }
    auto query = this->query();
    if (query.exec(QString(" drop table %1").arg(this->className))) {
        toRefleshGlobal(false);
        className.clear();
        emit classNameChanged(this->className);
        emit needToInitTbale();
        setClassName("");
        submitAll();
        return true;
    }
    return false;
}

bool FunctionModel::initTable()
{
    assert(className.isEmpty() && (database().isOpen())); /* {
        qDebug() << "database is not open";
        return false;
    }*/
    auto query = this->query();
    if (query.exec(QString("create if not exit table %1 (Name varchar primary key ,Type varchar, "
                           "Value varchar)")
                       .arg(className))) {
        setClassName(this->className);
        return true;
    }
    return false;
}

void FunctionModel::initHeader()
{
    setTable(className);
    this->setHeaderData(0, Qt::Horizontal, QString("Name"));
    this->setHeaderData(1, Qt::Horizontal, QString("Args"));
    this->setHeaderData(2, Qt::Horizontal, QString("Value"));
}
