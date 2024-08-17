#pragma once

#include <QThread>
#include "mac.h"

struct CaptureThread : QThread {
    Q_OBJECT

public:
    explicit CaptureThread(QObject *parent = nullptr) : QThread(parent) {}
    ~CaptureThread() override {}

    QString intfName_;
    void run() override;

signals:
    void captured(Mac mac);
};


