/**
  * @file street.h
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Hlavičkový modul k modulu street.cpp
  */

#ifndef STREET_H
#define STREET_H

#include <coordinate.h>
#include <QString>
#include <QVector>
#include <stop.h>
#include <QGraphicsLineItem>
#include <QDebug>
#include <math.h>
#include <QPen>

class Street
{
public:
    Street();
    Street(QString name, Coordinate start, Coordinate end);
    Coordinate getStart();
    Coordinate getEnd();
    QString getName();
    void insertStop(Stop stop);
    void sortStops();
    double getDistanceFromStart(Coordinate coordinate);
    Stop getStopOnPosition(int position);
    int getSizeOfStopList();
    int getDelay();
    void setDelay(int delay);
    QGraphicsLineItem* getStreetAsQraphicsLine();

private:
    /**
     * @brief start pozice počátku ulice
     */
    Coordinate start;
    /**
     * @brief end pozice konce ulice
     */
    Coordinate end;
    /**
     * @brief name jméno ulice
     */
    QString name;
    /**
     * @brief stopList vektor zastávek na ulici
     */
    QVector<Stop> stopList;
    /**
     * @brief delay zpoždění ulice
     */
    int delay = 0;
    /**
     * @brief line grafická reprezentace ulice
     */
    QGraphicsLineItem* line;

};

#endif // STREET_H
