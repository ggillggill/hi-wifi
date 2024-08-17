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

class Show : public QWidget
{
    Q_OBJECT
public:
    Show(QWidget *parent = nullptr);
    QSoundEffect effect;

    ~Show() {
        deleteLater();
    }

    void PlayWavFile(Mac macAddr);

    void OpenImgFile(Mac macAddr);

};


#endif // SHOW_H
