#include "show.h"
#include <QPixmap>

QSet<QString> playingMac_;

void Show::PlayWavFile()
{
	if (!ok_) return;

	MacMap::iterator it = wavMap_.find(mac_);
    if (it == wavMap_.end()) {
		qDebug() << "not found2" << mac_;
        return;
    }

    QString wavFileName = "wav/" + it.value();
    qDebug() << QFile::exists(wavFileName);

    if (!wavFileName.isEmpty()) {
		QObject::connect(&effect, &QSoundEffect::playingChanged, this, &Show::doPlayingChanged);
        QAudioDevice ad(QMediaDevices::defaultAudioOutput());
        effect.setAudioDevice(ad);
        effect.setSource(QUrl::fromLocalFile(wavFileName));
        effect.play();
    }
}

void Show::OpenImgFile()
{
	if (!ok_) return;

	MacMap::iterator it = imgMap_.find(mac_);
    if (it == imgMap_.end()) {
		qDebug() << "not found1"<<mac_;
        return;
    }

    QString imgFileName = "img/" + it.value();
    qDebug() << QFile::exists(imgFileName);

    if (!imgFileName.isEmpty()) {
        QImage img;

        if (!img.load(imgFileName)) {
            qDebug() << "Failed to load image:" << imgFileName;
            return;
        }

        QLabel *lbView = new QLabel;
        lbView->setPixmap(QPixmap::fromImage(img));

        lbView->setAlignment(Qt::AlignCenter);
		lbView->show();
		//lbView->showMaximized();
    }
}

void Show::doPlayingChanged()
{
	qDebug() << effect.isPlaying();
	if (!effect.isPlaying()) {
		playingMac_.remove(mac_);
		deleteLater();

	}
}
