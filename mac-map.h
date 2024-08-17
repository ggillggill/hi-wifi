#ifndef MAC-MAP_H
#define MAC-MAP_H

#include <QMap>
#include <QString>

struct MacMap : QMap<QString, QString> {
};

extern MacMap imgMap_, wavMap_;


void InitMacMap() {
    imgMap_.insert("c2fdf3393942", "이경문.jpg");
    wavMap_.insert("c2fdf3393942", "이경문.m4a");

    imgMap.insert("6a19dd9cf6cf", "김택우.jpg");
    wavMap_.insert("6a19dd9cf6cf", "김택우.wav");

    //wavMap_.insert("ee7ec697dea6", "박현준.jpg"); // todo
    //imgMap_.insert("ee7ec697dea6", "박현준.wav"); // todo

    //wavMap_.insert("6cacc26b618b", "오원영.jpg"); // todo
    //imgMap_.insert("6cacc26b618b", "오원영.wav");

    imgMap_.insert("42c2b145011e", "강성우.jpg");
    wavMap_.insert("42c2b145011e", "강성우.wav");

    imgMap_.insert("1aabcd0ee0e8", "전성현.jpg");
    wavMap_.insert("1aabcd0ee0e8", "전성현.wav");

    imgMap_.insert("ea544f2bcda8", "윤태호.jpg");
    wavMap_.insert("ea544f2bcda8", "윤태호.wav");

    imgMap_.insert("288eecadbb4d", "임학수.jpg"); //
    wavMap_.insert("288eecadbb4d", "임학수.wav");

    imgMap_.insert("640c9138c83e", "이승현.jpg");
    wavMap_.insert("640c9138c83e", "이승현.wav");

    imgMap_.insert("6661ef750144", "이승대.jpg");
    wavMap_.insert("6661ef750144", "이승대.wav");

    imgMap_.insert("daada476a606", "권보연.jpg");
    wavMap_.insert("daada476a606", "권보연.wav");

    imgMap_.insert("4ec404367494", "김은지.jpg");
    wavMap_.insert("4ec404367494", "김은지.wav");
}

#endif // MAC-MAP_H
