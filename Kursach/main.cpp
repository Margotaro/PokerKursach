#include <QApplication>
#include <iostream>
#include "card.h"
#include "detectcombination.h"
#include <QList>
#include "ai.h"
#include "carddesk.h"
#include "mainwindow.h"
#include "game.h"
#include <QList>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    Game::Play();

    return a.exec();
}
