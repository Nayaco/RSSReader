﻿#include "loading.h"
#include <qmath.h>
#include <QDebug>

Loading::Loading(QWidget *parent) : QWidget(parent), _index(0), _i(0), _interval(50) {
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //this->setAttribute(Qt::WA_TranslucentBackground, true);

    setDotColor(QColor(49, 177, 190));
    setDotCount(20);
    connect(&timer, &QTimer::timeout, this, &Loading::refresh);
    setMaxDiameter(30);
    setMinDiameter(5);
}

void Loading::setDotCount(int count) {
    _count = count;
}

void Loading::setDotColor(const QColor& color) {
    _dotColor = color;
}

void Loading::start() {
    timer.setInterval(_interval);
    timer.start();
}

void Loading::setMaxDiameter(float max) {
    _maxDiameter = max;
}

void Loading::setMinDiameter(float min) {
    _minDiameter = min;
}

void Loading::refresh() {
    repaint();
}

void Loading::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event)
    caculate();
}

void Loading::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(_dotColor);
    painter.setBrush(_dotColor);

    paintDot(painter);
}

void Loading::caculate() {
    _squareWidth = qMin(this->width(), this->height());
    float half = _squareWidth / 4;
    _centerDistance = half - _maxDiameter / 2 - 1;

    float gap = (_maxDiameter - _minDiameter) / (_count - 1) / 2;
    float angleGap = (float)360 / _count;

    locationList.clear();
    radiiList.clear();

    for(int i = 0; i < _count; i++) {
        radiiList << _maxDiameter / 2 - i * gap;
        float radian = qDegreesToRadians(-angleGap * i);
        locationList.append(Location(half + _centerDistance * qCos(radian), half - _centerDistance * qSin(radian)));
    }
}

void Loading::paintDot(QPainter& painter) {
    for(int i = 0; i < _count; i++) {
        painter.setPen(_dotColor);
        float radii = radiiList.at((_index + _count - i) % _count);
        painter.drawEllipse(QPointF(locationList.at(i).x, locationList.at(i).y), radii, radii);
    }
    _index++;
}
