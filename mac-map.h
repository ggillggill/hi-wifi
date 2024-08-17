#ifndef MAC-MAP_H
#define MAC-MAP_H

#include <QMap>
#include <QString>

struct MacMap : QMap<QString, QString> {
} imgMap_, wavMap_;


void InitMacMap() {
    wavMap_.insert("c2fdf3393942", "이경문.jpg");
    imgMap_.insert("c2fdf3393942", "이경문.m4a");

    wavMap_.insert("6a19dd9cf6cf", "김택우.jpg");
    imgMap_.insert("6a19dd9cf6cf", "김택우.wav");

    //wavMap_.insert("ee7ec697dea6", "박현준.jpg"); // todo
    //imgMap_.insert("ee7ec697dea6", "박현준.wav"); // todo

    //wavMap_.insert("6cacc26b618b", "오원영.jpg"); // todo
    //imgMap_.insert("6cacc26b618b", "오원영.wav");

    wavMap_.insert("42c2b145011e", "강성우.jpg");
    imgMap_.insert("42c2b145011e", "강성우.wav");
}

#endif // MAC-MAP_H
