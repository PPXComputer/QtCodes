#ifndef MUSICMEATA_H
#define MUSICMEATA_H

#include "imageprovider.h"
#include "infomusic.h"
#include <QObject>
class MusicMeata : public QObject
{
    Q_OBJECT
public:
    explicit MusicMeata(QObject *parent = nullptr);

    ImageProvider *getProvider() const;

    InfoMusic *getMusicData() const;
    ~MusicMeata() = default;
signals:

public slots:
private:
    InfoMusic *musicData = nullptr;

    ImageProvider *provider = nullptr;
};

#endif // MUSICMEATA_H
