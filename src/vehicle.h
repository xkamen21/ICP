/**
  * @file vehicle.h
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Hlavičkový modul k modulu vehicle.cpp
  */

#include <coordinate.h>
#include <path.h>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QDebug>

#ifndef VEHICLE_H
#define VEHICLE_H


class Vehicle
{

public:
    Vehicle();
    Vehicle(Coordinate position, double speed, Path path, int color);
    QGraphicsEllipseItem* getEllipse();
    void vehMove(Coordinate coordinate);
    void vehUpdate(int hours);
    bool direction = true; //promenna pro zpetnou cestu, pri false vime ze jede na zpatek
    Path getPath();
    double getDistance();
    bool isAtStart();
    bool compareWithTollerance(double a, double b);

private:
    /**
     * @brief position aktuální pozice vozidla
     */
    Coordinate position;
    /**
     * @brief speed rychlost vozidla
     */
    double speed;
    /**
     * @brief distance ujetá vzdálenost vozidla
     */
    double distance = 0;
    /**
     * @brief path trasa vozidla
     */
    Path path;
    /**
     * @brief stopWaiter časovač pro čekání na zastávce
     */
    int stopWaiter = 0;
    /**
     * @brief visual grafická reprezentace vozidla
     */
    QGraphicsEllipseItem *visual;
    /**
     * @brief countWait zabránění vícenásobného čekání na zastávce
     */
    int countWait = 0;
    /**
     * @brief EndPathWaiter časovač čekání na konci trasy/linky
     */
    int EndPathWaiter = 0;


};



#endif // VEHICLE_H
