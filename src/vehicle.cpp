/**
  * @file vehicle.cpp
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Modul zpracovávající data vozidel.
  */

#include "vehicle.h"
#include <cstdlib>

//Vehicle v konecne zastavce bude cekat dobu, ktera odpovida intervalu. Do vehicle pridat timer ktery bude zvysovat velikost pri tiku hodin, pri naplneni anulovat a vyslat zpet.

/**
 * @brief Vehicle::Vehicle konstruktor
 */
Vehicle::Vehicle()
{

}

/**
 * @brief Vehicle::Vehicle konstruktor
 * @param position počáteční pozice vozidla
 * @param speed rychlost vozidla
 * @param path trasa vozidla
 * @param color barva vozidla
 */
Vehicle::Vehicle(Coordinate position, double speed, Path path, int color)
{
    if(speed>90)
        speed = 90;
    if(speed<50)
        speed = 50;

    this->speed = speed;
    this->position = position;
    this->path = path;
    this->visual = new QGraphicsEllipseItem ();
    this->visual->setRect(position.getX()-5, position.getY()-5, 10, 10);
    this->visual->setBrush(QBrush(QColor(color)));
}

/**
 * @brief Vehicle::getDistance
 * @return Vrátí ujetou vzdálenost auta
 */
double Vehicle::getDistance(){
    return distance;
}

/**
 * @brief Vehicle::getEllipse
 * @return vrátí ukazatel na vozidlo (typu QGraphicsEllipseItem*)
 */
QGraphicsEllipseItem* Vehicle::getEllipse(){
    return visual;
}

/**
 * @brief Vehicle::vehMove Nastaví pozici vozidla na danou pozici
 * @param coordinate souřadnice nastavovaného místa
 */
void Vehicle::vehMove(Coordinate coordinate){
    visual->setRect(coordinate.getX()-5, coordinate.getY()-5, 10, 10);
}

/**
 * @brief Vehicle::vehUpdate Zaopatřuje pohyb vozidla v čase.
 * @param hours časový údaj v hodinách
 */
void Vehicle::vehUpdate(int hours){
    int WaitingTime = 0;
    if(path.stopSameAsPosition(position) && stopWaiter != 300 && countWait == 0){
        stopWaiter++;
        return;
    }
    else{
        countWait++;
        stopWaiter = 0;
    }
    if(!path.stopSameAsPosition(position) && countWait != 0){
        countWait = 0;
    }
    Street* street = path.getStreetWithVehicle(distance, direction);
    distance+=speed/(200+street->getDelay());
    if(distance >= path.getPathValue())
    {
        if(hours==23 || hours<6){
            WaitingTime = 30*60*20;
        }
        else{
            WaitingTime = path.pathGetInterval()*60*20;
        }
        if((EndPathWaiter < WaitingTime) && direction){
            EndPathWaiter++;
            return;
        }
        else{
            distance = 0;
            EndPathWaiter = 0;
            if(direction)
                direction = false;
            else
                direction = true;
        }
    }
    Coordinate coords = path.getCoordinateByDistance(distance, direction);
    vehMove(coords);
    position = coords;
}
///Metoda pro posun vozidla v čase. Zajišťuje čekání vozidla na zastávkách a na konečné zastávce.
/// Dbá na rozdíl mezi nočním a denním časem.

/**
 * @brief Vehicle::getPath
 * @return Vrátí linku vozidla.
 */
Path Vehicle::getPath()
{
    return path;
}

/**
 * @brief Vehicle::isAtStart
 * @return Vrátí true pokud je vozidlo na staru linky.
 */
bool Vehicle::isAtStart()
{
    //   (qRound(position.getX()) == qRound(path.pathGetStart().getX()) && qRound(position.getY()) == qRound(path.pathGetStart().getY()))
    if (compareWithTollerance(position.getX(), path.pathGetStart().getX()) && compareWithTollerance(position.getY(), path.pathGetStart().getY()))
    {
        return true;
    }
    return false;
}

/**
 * @brief Vehicle::compareWithTollerance Pomocná funkce porovnávající 2 čísla s určitou tolerancí.
 * @param a číslo pro porovnání
 * @param b číslo pro porovnání
 * @return Vrátí true pokud jsou shodné (s danou tolerancí)
 */
bool Vehicle::compareWithTollerance(double a, double b)
{
    auto diff = a - b;
    return (diff < 10) && (-diff < 10);
}
