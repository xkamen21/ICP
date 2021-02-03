/**
  * @file sceneedit.cpp
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Modul zpracovávající interaktivní zásah do scény - zvýraznění linky.
  */

#include "sceneedit.h"

/**
 * @brief SceneEdit::SceneEdit defaultní konstruktor
 * @param parent rodic typu QParent
 */
SceneEdit::SceneEdit(QObject *parent) : QGraphicsScene(parent)
{
}

/**
 * @brief SceneEdit::SceneEdit konstruktor
 * @param view
 * @param vehicleVector
 * @param streetVector
 * @param uii
 * @param PositionOfDelaydedstreet
 */
SceneEdit::SceneEdit(QGraphicsView *view, QVector<Vehicle>* vehicleVector, QVector<Street*> streetVector, Ui::MainWindow* uii, int* PositionOfDelaydedstreet)
{
    this->view = view;
    this->vehicleVector = vehicleVector;
    this->streetVector = streetVector;
    this->uii = *uii;
    this->PositionOfDelaydedstreet = PositionOfDelaydedstreet;
    setLinkInfo();
}

/**
 * @brief SceneEdit::printLink Nastaví výpis zastávek dané linky + jizdní řád z výchozí stanice.
 * @param vehicle konkretní vozidlo
 * @return Vraci string vypisující linku a všechny její zastávky.
 */
QString SceneEdit::printLink(QGraphicsEllipseItem *vehicle)
{
    bool flag = true;
    QString output = "Link ";
    QString timetable = "Starting station timetable:\n";
    QVector<Vehicle>:: iterator it;
    for (it = vehicleVector->begin(); it != vehicleVector->end(); it++) {
        if(it->getEllipse() == vehicle)
        {
            flag = false;
            output.append(QString::number(it->getPath().pathGetLinkName(),10));
            output.append("\n\nStops: \n");

            //qDebug() << it->getPath().pathGetLinkName() << " se zastavkami: ";
            QVector<Stop> stopList = it->getPath().pathGetStopList();
            QVector<Stop>:: iterator it2;
            for (it2 = stopList.begin(); it2 != stopList.end(); it2++) {
                output.append(" ->  " + it2->getName() + '\n');
            }

            //output.append("\n\n\nStarting station timetable:\n");
            for(int i = 0; i < 6; i++)
            {
                timetable.append(QString::number(i)+": 00 30 \n");
            }
            for(int i = 6; i< 23; i++)
            {
                timetable.append(QString::number(i)+ ": ");
                if(it->getPath().pathGetInterval() == 1)
                {
                    timetable.append("every minute");
                }
                else if(it->getPath().pathGetInterval() == 2 || it->getPath().pathGetInterval() == 3)
                {
                    timetable.append("every "+QString::number(it->getPath().pathGetInterval())+" minutes");
                }
                else
                {
                    for(int j = 0; j < 59; j++)
                    {
                        //output.append(QString::number((i*60+j) % (it->getPath().pathGetInterval)()));
                        if((((i-6)*60+j) % (it->getPath().pathGetInterval)()) == 0)
                        {
                            if(j<10)
                            {
                                timetable.append("0");
                            }
                                timetable.append(QString::number(j)+" ");
                        }
                    }
                }
                timetable.append("\n");
            }
            timetable.append("23: 00 30 \n");
            uii.TimeTable->setText(timetable);

            //qDebug() << it->getPath().getStreetList().size();
            QVector<Street*> tmpList =  it->getPath().getStreetList();
            for(int i = 0; i < tmpList.size(); i++)
            {
                tmpList[i]->getStreetAsQraphicsLine()->setPen(QPen(QColor(Qt::green),2));
            }

        }
    }
    if(flag)
    {
        output.append("Link -\n\n Click on vehicle for info");
    }
    return output;
}

/**
 * @brief SceneEdit::getStreet
 * @param street
 */
void SceneEdit::getStreet(QGraphicsLineItem* street){
    for(int i = 0; i<streetVector.size(); i++){
        if( streetVector[i]->getStart().getX() == street->line().x1() && streetVector[i]->getEnd().getX() == street->line().x2() && streetVector[i]->getStart().getY() == street->line().y1() && streetVector[i]->getEnd().getY() == street->line().y2() ) {
            if(*PositionOfDelaydedstreet == i){
                streetVector[i]->getStreetAsQraphicsLine()->setPen(QPen(QColor(Qt::black),2));
                *PositionOfDelaydedstreet = -1;
                uii.streetName->setText("Click on street for name");
                uii.printDelay->setText("Click on street for delay");
            }
            else{
                if(*PositionOfDelaydedstreet != -1)
                {
                    streetVector[*PositionOfDelaydedstreet]->getStreetAsQraphicsLine()->setPen(QPen(QColor(Qt::black),2));
                }
                streetVector[i]->getStreetAsQraphicsLine()->setPen(QPen(QColor(Qt::red),2));
                uii.streetName->setAlignment(Qt::AlignCenter);
                uii.printDelay->setAlignment(Qt::AlignCenter);
                uii.streetName->setText(streetVector[i]->getName());
                int delay = streetVector[i]->getDelay();
                delay = delay/200;
                if(delay>100){
                    delay = 100;
                }
                uii.printDelay->setText("Delay is on: "+QString::number(delay)+"%");
                *PositionOfDelaydedstreet = i;
            }
            return;
        }
    }
}

/**
 * @brief SceneEdit::resetMarkedLine Po odznačení ulice vrátí barvu na černou.
 */
void SceneEdit::resetMarkedLine()
{
    if(*PositionOfDelaydedstreet != -1)
    {
        streetVector[*PositionOfDelaydedstreet]->getStreetAsQraphicsLine()->setPen(QPen(QColor(Qt::black),2));
        *PositionOfDelaydedstreet = -1;
        uii.streetName->setText("Click on street for name");
        uii.printDelay->setText("Click on street for delay");
    }
}
/**
 * @brief SceneEdit::setLinkInfo Při neaktivním výpísu linky nastavi úvodní text.
 */
void SceneEdit::setLinkInfo()
{
    QString output = "Link -";
    output.append("\n\n Click on vehicle for info");
    this->uii.VehicleData->setFontWeight(3);
    this->uii.VehicleData->setText(output);
    this->uii.VehicleData->setAlignment(Qt::AlignCenter);
    this->uii.TimeTable->setFontWeight(3);
    this->uii.TimeTable->clear();
    this->uii.printDelay->setAlignment(Qt::AlignCenter);
    this->uii.streetName->setAlignment(Qt::AlignCenter);
    this->uii.streetName->setText("Click on street for name");
    this->uii.printDelay->setText("Click on street for delay");
}

/**
 * @brief SceneEdit::resetStreets Přebarví všechny ulice na úvodní barvu černou.
 */
void SceneEdit::resetStreets()
{
    for(int i = 0; i < streetVector.size(); i++)
    {
        streetVector[i]->getStreetAsQraphicsLine()->setPen(QPen(QColor(Qt::black),2));
    }
}

/**
 * @brief SceneEdit::mousePressEvent Zachycuje kliknutí na jednotlivé objekty ve scéně.
 * @param event kliknutí myši
 */
void SceneEdit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /// Po kliknutí na objekt vyhodntí zda-il bylo kliknuto na vozidlo nebo ulici a zavolá příslušnou funkci.
    /// Také se stará o případně přebarení ulic.
    for(auto* item: items(event->scenePos()) )
    {
        auto vehicle =  dynamic_cast<QGraphicsEllipseItem*>(item);
        auto street = dynamic_cast<QGraphicsLineItem*>(item);
        if ( vehicle != nullptr)
        {
            resetStreets();
            resetMarkedLine();
            //qDebug() << "auto" << vehicleVector[0].data()->visual << "kliknuto na" << vehicle;
            uii.VehicleData->setText(printLink(vehicle));
            uii.VehicleData->setAlignment(Qt::AlignCenter);
            return;
        }
        else if(street != nullptr)
        {
            resetStreets();
            setLinkInfo();
            getStreet(street);
            return;
        }
        else
        {
            resetMarkedLine();
        }
    }
    resetMarkedLine();
    setLinkInfo();
    resetStreets();

    QGraphicsScene::mousePressEvent(event);
}
