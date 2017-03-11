#include <QCoreApplication>
#include <iostream>
#include "card.h"
#include "detectcombination.h"
#include "flashroyale.h"
#include "straightflush.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //DetectCombination::c = true;
    //cout << DetectCombination::returnTrue() ? "asd" : "dfg" << endl;
    FlashRoyale* fr = new FlashRoyale();
    StraightFlush* sr = new StraightFlush(new Card(Suit::HEARTS, Rank::TEN));
    cout << (fr->compareTo((Combination*)sr) ? "Royal >" : "Street <\n");
    cout << (sr->compareTo((Combination*)fr) ? "Royal <" : "Street >");
    return a.exec();
}
