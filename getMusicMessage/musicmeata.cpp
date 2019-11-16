#include "musicmeata.h"

MusicMeata::MusicMeata(QObject *parent) : QObject(parent)
{
    musicData = new InfoMusic{"qrc:/music/Various Artists - Distant Shores.mp3", parent};
    provider = new ImageProvider(parent);
    connect(musicData, &InfoMusic::getInformation, [](const InfoMusic::InfoMusicType data) {
        qDebug() << "打印出来结果  " + data.album << " "
                 << " " << data.author << "  " << data.filePath;
    });
    connect(musicData, &InfoMusic::getCoverImage, provider, &ImageProvider::setImg);
    musicData->getMessage();
}

ImageProvider *MusicMeata::getProvider() const
{
    return provider;
}

InfoMusic *MusicMeata::getMusicData() const
{
    return musicData;
}
