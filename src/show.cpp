#include "show.h"
#include <QPixmap>

Show::Show(QWidget *parent) : QWidget(parent){}

void Show::PlayWavFile(Mac macAddr)
{
    QString macStr = QString::fromStdString(std::string(macAddr));
    macStr = macStr.replace(":", "").toLower();
    MacMap::iterator it = wavMap_.find(macStr);
    if (it == wavMap_.end()) {
        qDebug() << "not found2" << macStr;
        return;
    }

    QString wavFileName = "wav/" + it.value();
    qDebug() << QFile::exists(wavFileName);

    if (!wavFileName.isEmpty()) {
        QAudioDevice ad(QMediaDevices::defaultAudioOutput());
        effect.setAudioDevice(ad);
        effect.setSource(QUrl::fromLocalFile(wavFileName));
        effect.play();
    }
}

void Show::OpenImgFile(Mac macAddr)
{
    QString macStr = QString::fromStdString(std::string(macAddr));
    macStr = macStr.replace(":", "").toLower();
    MacMap::iterator it = imgMap_.find(macStr);
    if (it == imgMap_.end()) {
        qDebug() << "not found1"<<macStr;
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
        lbView->showMaximized();
    }
}
