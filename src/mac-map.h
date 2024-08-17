#pragma once

#include <QMap>
#include <QString>

struct MacMap : QMap<QString, QString> {
};

extern MacMap imgMap_, wavMap_;

void InitMacMap();
