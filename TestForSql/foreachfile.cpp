#include "foreachfile.h"

ForEachFile::ForEachFile(QObject *parent) : QObject(parent)
{
    connect(this, &ForEachFile::filePathChanged, this, &ForEachFile::createFile);
}

void ForEachFile::setFilePath(QString path)
{
    this->filePath = std::move(path);

    if (QUrl dir = filePath; dir.isValid()) {
        emit filePathChanged(filePath);
    } else {
        emit filePathError();
    }
}

// 在文件的路径确定后  创建文件 与其相关的 base.db  并将所有在此文件下的model使用此 base.db
void ForEachFile::createFile()
{
    QDir check{filePath};
    if (check.exists()) {
        emit filePathError();
    } else {
        if (!check.mkdir(filePath))
            emit filePathError();
        else {
            emit createCompleted();
        }
    }
}
