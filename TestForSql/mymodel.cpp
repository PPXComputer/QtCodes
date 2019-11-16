#include "mymodel.h"

MyModel::MyModel(QObject *parent) : QSqlTableModel (parent)
{
    initHeader();
    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    connect(this, &MyModel::tableNameChanged, this, &MyModel::initTable);
}

QVariant MyModel::data(const QModelIndex &index, int role) const
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

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

QHash<int, QByteArray> MyModel::roleNames() const
{
    //设置为 UseRole使用的大量数据
    QHash<int, QByteArray> roleNames;
    for (int i = 0; i < record().count(); i++) {
        roleNames[Qt::UserRole + i + 1] = record().fieldName(i).toUtf8();
    }
    return roleNames;
}

void MyModel::initHeader()
{
    setTable(tableName);
    this->setHeaderData(0, Qt::Horizontal, QString("Value"));
    this->setHeaderData(1, Qt::Horizontal, QString("Name"));
    this->setHeaderData(2, Qt::Horizontal, QString("Args"));
}

bool MyModel::initTable()
{
    QSqlQuery query;
    if (!query.exec(
            QString("create table if not exists %1 ( Name varchar ,Args varchar ,Value varchar)")
                .arg(tableName))) {
        qDebug()<<"创建表格错误"<<query.lastError ();
        return false;
    }
    QSqlTableModel::setTable(this->tableName);
    this->submitAll();
    return true;
}
