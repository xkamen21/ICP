/**
  * @file mainwindow.h
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Hlavičkový modul k modulu mainwindow.cpp
  */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMap>
#include <QDebug>
#include <QtWidgets>
#include <QRect>
#include <coordinate.h>
#include <QGraphicsItem>
#include <jsonread.h>
#include <sceneedit.h>
#include <QDateTime>
#include <street.h>
#include <QGraphicsScene>
#include <street.h>
#include <path.h>
#include <vehicle.h>
#include <stop.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    // POkud chci mit objekt co vysila signaly musi to dedit z QObject

public:
    /**
     * @brief vehicleVector vektro všech aktuálních vozidel
     */
    QVector<Vehicle> vehicleVector;
    /**
     * @brief coordinateVector vektor všech potřebných souřadnic
     */
    QVector<Coordinate> coordinateVector;
    /**
     * @brief stopVector vektor všech zastávek
     */
    QVector<Stop> stopVector;
    /**
     * @brief streetVector vektor všech ulic
     */
    QVector<Street*> streetVector;
    /**
     * @brief pathVector vektor všech linek
     */
    QVector<Path> pathVector;
    /**
     * @brief scene hlavní scéna
     */
    QGraphicsScene* scene;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void StartTime();
    QString TimeSetter();
    void AddingStopIntoStreet();
    void setPaths();
    void setScene(QVector<Street*> streetVector);
    void startVehicle();
    void resetDelay();
    void increaseDelay();
    void decreaseDelay();
    void increaseHour();
    void decreaseHour();
    void increaseMinute();
    void decreaseMinute();
    void increaseSecond();
    void decreaseSecond();
    void setNewTime();

signals:
    void signalChanged(int val);

public slots:
    void TimeUpdate();

private slots:
    void zoom(int val); // kdyz zde mam ukazatel tak alt + Enter mi vyvori deklaraci te funkce
    void timeChanged (int val);
private:
    /**
     * @brief ui uživatelské rozhraní
     */
    Ui::MainWindow *ui;
    /**
     * @brief timer čas
     */
    QTimer *timer;
    /**
     * @brief seconds proměnná pro virtuální zastoupení sekund
     */
    int seconds = 0;
    /**
     * @brief seconds proměnná pro virtuální zastoupení minut
     */
    int minutes = 0;
    /**
     * @brief seconds proměnná pro virtuální zastoupení hodin
     */
    int hours = 0;
    /**
     * @brief timeupdate proměnná pro update času, vícekrát se updatene vozidlo než čas, počítadlo rozdílu
     */
    int timeupdate = 0;
    /**
     * @brief DelaydedStreet index editované ulice
     */
    int DelaydedStreet = -1;
};
#endif // MAINWINDOW_H
