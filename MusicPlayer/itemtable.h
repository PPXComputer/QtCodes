#ifndef ITEMTABLE_H
#define ITEMTABLE_H

#include <QObject>
#include <QStringList>
class ItemTable : public QObject
{
    Q_OBJECT
public:
    explicit ItemTable(QObject *parent = nullptr);

signals:

public slots:

private:
    QString m_string;
};

#endif // ITEMTABLE_H
