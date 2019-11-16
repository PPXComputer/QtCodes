#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include<QtCore>
#include<QtGui>
class MyModel : public QSqlTa
{
    Q_OBJECT
public:
    explicit MyModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYMODEL_H
