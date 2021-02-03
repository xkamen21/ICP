/**
  * @file path.h
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Hlavičkový modul k modulu path.cpp
  */

#ifndef PATH_H
#define PATH_H

#include <QList>
#include <coordinate.h>
#include <stop.h>
#include <street.h>
#include <math.h>
#include <QDebug>

class Path
{
public:
    Path();
    Path(QList<Coordinate> pathList);
    Path(QVector<QString> streetNames, double speed, double linkNumber, double interval, int color);

    double getDistanceOfCoordinates(Coordinate a, Coordinate b);
    Coordinate getCoordinateByDistance (double distance, bool direction);
    double getPathValue();
    bool stopSameAsPosition(Coordinate coordinate);
    void setStreetsAndStops(QVector<Street*> streetVector);
    Coordinate pathGetStart();
    double pathGetSpeed();
    int getColor();
    int pathGetInterval();
    int pathGetLinkName();
    QVector<Stop> pathGetStopList();
    Street* getStreetWithVehicle(double distance, bool direction);
    QVector<Street*> getStreetList();


private:
    /**
     * @brief pathList trasa vozidla reprezentována listem souřadnic
     */
    QList<Coordinate> pathList;
    /**
     * @brief stopList vektor ulic trasy
     */
    QVector<Stop> stopList;
    /**
     * @brief streetList vektor ulic trasy
     */
    QVector<Street*> streetList;
    /**
     * @brief streetNames vektor jmen ulic trasy
     */
    QVector<QString> streetNames;
    /**
     * @brief stopNames vektro jmen zastávek trasy
     */
    QVector<QString> stopNames;
    /**
     * @brief speed rychlost vozidel na trase
     */
    double speed;
    /**
     * @brief pathNumber číslo linky
     */
    double pathNumber;
    /**
     * @brief interval doba rozestupu v minutách mezi výjezdem z počáteční zastávky
     */
    double interval;
    /**
     * @brief color barva vozidel linky
     */
    int color;
};

#endif // PATH_H
