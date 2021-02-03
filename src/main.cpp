/**
  * @file  main.cpp
  * @authors Daniel Kamenický xkamen21
  * <br/>Marek Fiala xfiala60
  * @details Spouštění programu.
  */

/*! \mainpage Dokumentace k semestrálnímu projektu
 *
 * \section Předmět Seminář C++
 * \subsection Popis
 * Semestrální projekt - aplikace pro zobrazení linek hromadné dopravy a sledování jejich pohybu.
 * @authors Daniel Kamenický xkamen21
 * <br/>Marek Fiala xfiala60
 *
 * @date Květen 2020
 */
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
