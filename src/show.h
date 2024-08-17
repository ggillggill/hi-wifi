#ifndef SHOW_H
#define SHOW_H

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QImage>
#include <QWidget>
#include <QSoundEffect>
#include <QMediaDevices>
#include <QAudioDevice>
#include <QLabel>
#include <QFile>
#include <QPixmap>
#include "mac.h"
#include "mac-map.h"

extern QSet<QString> playingMac_;

class Show : public QWidget
{
    Q_OBJECT
public:
	Show(QWidget *parent, QString mac) : QWidget(parent), mac_(mac) {
		if ((playingMac_.find(mac) == playingMac_.end())) {
			qDebug() << "ok!!!";
			ok_ = true;
			playingMac_.insert(mac);
		} else {
			qDebug() << "not ok!!!";
			ok_ = false;
		}
	}
	bool ok_;
	QString mac_;
    QSoundEffect effect;

    ~Show() {
        deleteLater();
    }

	void PlayWavFile();

	void OpenImgFile();

public slots:
	void doPlayingChanged();
};


#endif // SHOW_H
