/**
  * @file jsonread.h
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Hlavičkový modul k modulu jsonread.cpp
  */
#ifndef JSONREAD_H
#define JSONREAD_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <stop.h>
#include <street.h>
#include <path.h>


class JsonRead
{
public:
    JsonRead();
    void ReadJson(QVector<Stop>* stopVector, QVector<Street*>* streetVector, QVector <Path>* pathVector);
    double getXorYfrom(QJsonObject Object, QString name, QString XorY);
};

#endif // JSONREAD_H
