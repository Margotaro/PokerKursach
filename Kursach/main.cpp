#include <QApplication>
#include <iostream>
#include "card.h"
#include "detectcombination.h"
#include <QList>
#include "ai.h"
#include "carddesk.h"
#include "mainwindow.h"
#include <QList>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;

    CardDesk stopka;
    stopka.fill();
    stopka.shuffle();

    Table *stol = new Table;
    You *user = new You();
    AI *kitty = new AI(1);

    stol->addToCommunityCards(stopka.getDeck()[0]);
    stol->addToCommunityCards(stopka.getDeck()[1]);
    stol->addToCommunityCards(stopka.getDeck()[2]);
    stol->addToCommunityCards(stopka.getDeck()[3]);

    kitty->TakeaCard(new Card(CLUBS, KING));
    kitty->TakeaCard(new Card(DIAMONDS, TWO));

    kitty->Parlay(stol);

    window.show();

    return a.exec();
}
