#include "membermodel.h"

MemberModel::MemberModel(QObject *parent)
    : QSqlTableModel(parent, QSqlDatabase::addDatabase("SQLITE", "localPath"))
{
    initHeader();
    this->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
    connect(this,
            &MemberModel::classNameChanged,
            this,
            &MemberModel::initTable,
            Qt::QueuedConnection);
}

QVariant MemberModel::data(const QModelIndex &index, int role) const
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

bool MemberModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

QHash<int, QByteArray> MemberModel::roleNames() const
{
    //设置为 UseRole使用的大量数据
    QHash<int, QByteArray> roleNames;
    for (int i = 0; i < record().count(); i++) {
        roleNames[Qt::UserRole + i + 1] = record().fieldName(i).toUtf8();
    }
    return roleNames;
}

QString MemberModel::getclassName() const
{
    return className.left(className.indexOf("_Member"));
}

void MemberModel::setclassName(QString value)
{
    if (value.contains("_Member")) {
        emit needToResetClassName();
        return;
    }
    auto name = value + "_Member";
    if (className != name) {
        className = std::move(name);
        emit classNameChanged(className);
    }
}

bool MemberModel::addMember(QString &type, QString &name)
{
    if (!database().tables().contains(this->className)) {
        return false;
    }
    auto query = this->query();
    query.prepare(QString("insert into :table ( Name ,Type ) values ( ':name' , ':type' )"));
    query.bindValue(":table", this->className);
    query.bindValue(":name", name);
    query.bindValue(":type", type);

    return query.exec() && submitAll();
}

bool MemberModel::deleteMember(QString &name)
{
    if (!database().tables().contains(this->className)) {
        return false;
    }
    auto query = this->query();
    query.prepare(QString("delete  from :table where Name = ' :name '"));
    query.bindValue(":name", name);
    return query.exec() && submitAll();
}

bool MemberModel::dropTable()
{
    if (!database().tables().contains(this->className)) {
        return false;
    }
    auto query = this->query();
    if (query.exec(QString(" drop table %1").arg(this->className))) {
        toRefleshGlobal(false);
        className.clear();
        emit classNameChanged(this->className);
        emit needToInitTbale();
        submitAll();
        return true;
    }
    return false;
}

bool MemberModel::initTable()
{
    if (!className.isEmpty()) {
        if (database().isOpen()) {
            if ((!database().tables().contains(className))) {
                auto query = this->query();
                if (query.exec(QString("create table %1 ( Name varchar primary key ,Type varchar )")
                                   .arg(this->className))) {
                    setTable(this->className);
                    toRefleshGlobal(true);
                    return true;
                }
            } else {
                qDebug() << "exit table " << className;
                return false;
            }
        } else {
            qDebug() << "database is not open";
            return false;
        }
    }
    return false;
}

void MemberModel::initHeader()
{
    setTable(className);
    this->setHeaderData(0, Qt::Horizontal, QString("Name"));
    this->setHeaderData(1, Qt::Horizontal, QString("Type"));
}

bool MemberModel::toRefleshGlobal(bool addOrDel) {}
