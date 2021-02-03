/**
  * @file sceneedit.h
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Hlavičkový modul k modulu sceneedit.cpp
  */
#ifndef SCENEEDIT_H
#define SCENEEDIT_H

#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QMouseEvent>
#include <vehicle.h>
#include <QGraphicsView>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <vehicle.h>
#include <QPen>

class SceneEdit : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SceneEdit(QObject *parent = nullptr);
    SceneEdit(QGraphicsView* view, QVector<Vehicle>* vehicleVector, QVector<Street*> streetVector, Ui::MainWindow* uii, int* PositionOfDelaydedstreet);
    void mouseReleaseEvent2(QMouseEvent *event);
    void mousePressEvent2(QMouseEvent *event);
    void mouseMoveEvent2(QMouseEvent *event);
    QString printLink(QGraphicsEllipseItem* vehicle);
    void getStreet(QGraphicsLineItem* street);
    void resetMarkedLine();
    void setLinkInfo();
    void resetStreets();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    /**
     * @brief vehicleVector vektro všech aktuálních vozidel
     */
    QVector<Vehicle>* vehicleVector;
    /**
     * @brief streetVector vektor všech ulic
     */
    QVector<Street*> streetVector;
    /**
     * @brief ui proměnná pro práci s myšší
     */
    QGraphicsSceneMouseEvent* ui;
    /**
     * @brief view
     */
    QGraphicsView* view;
    /**
     * @brief uii  uživatelské rozhraní
     */
    Ui::MainWindow uii;
    /**
     * @brief PositionOfDelaydedstreet index editované ulice
     */
    int* PositionOfDelaydedstreet;;
};

#endif // SCENEEDIT_H
