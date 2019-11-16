#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>

class FileReader : public QObject
{
    Q_OBJECT
public:
    explicit FileReader(QObject *parent = nullptr);
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
signals:
    //Q_INVOKABLE
public slots:
};

#endif // FILEREADER_H
