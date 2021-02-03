/**
  * @file stop.cpp
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Modul zpracovávající data zastávek.
  */

#include "stop.h"
/**
 * @brief Stop::Stop defaultní konstruktor
 */
Stop::Stop(){}

/**
 * @brief Stop::Stop konstruktor
 * @param name jméno zastávky
 * @param position pozice zastávky
 */
Stop::Stop(QString name, Coordinate position)
{
    this->name = name;
    this->position = position;
}

/**
 * @brief Stop::getPosition
 * @return Vrátí pozici zastávky.
 */
Coordinate Stop::getPosition(){
    return position;
}

/**
 * @brief Stop::getName
 * @return Vrátí jméno zastávky.
 */
QString Stop::getName(){
    return name;
}

