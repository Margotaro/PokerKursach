#ifndef DETECTCOMBINATION_H
#define DETECTCOMBINATION_H

#include "combination.h"
#include "flashroyale.h"
#include "straightflush.h"
#include "card.h"
#include "fourofakind.h"
#include "fullhouse.h"
#include "flush.h"
#include "straight.h"
#include "set.h"
#include "twopair.h"
#include "onepair.h"
#include "highcard.h"

#include <QList>

class DetectCombination
{
private:
    bool maybeCombination[5];
    QList<Card* > n_clubs, n_diamonds, n_hearts, n_spades;
    int nRanks[14];
public:
    DetectCombination();
    static Combination* Detect(QList<Card*> cards);
    FlashRoyale* DetectFlashRoyale(QList<Card *> cards);
    StraightFlush* DetectStraightFlush(QList<Card *> cards);
    FourOfaKind* DetectFourOfaKind(QList<Card *> cards);
    FullHouse* DetectFullHouse(QList<Card *> cards);
    Flush* DetectFlush(QList<Card*> cards);
    Straight* DetectStraight(QList<Card*> cards);
    Set* DetectSet(QList<Card*> cards);
    TwoPair* DetectTwoPair(QList<Card*> cards);
    OnePair* DetectOnePair(QList<Card*> cards);

    Card* getHighestCard(QList<Card*> cards);
};

#endif // DETECTCOMBINATION_H
