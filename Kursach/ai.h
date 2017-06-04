#ifndef AI_H
#define AI_H
#include "table.h"
#include <QList>
#include <iostream>
#include "card.h"
#include "detectcombination.h"
#include "player.h"
#include "time.h"
#include <math.h>

class Table;

class AI : public Player
{
    int personality;
public:
    AI(int cs = 0);
    virtual void TakeaCard(Card* card);
    // Процентность вероятности удачной комбинации, симуляция artifical intelligence
    float GetConfidence(QList<Card*> &myDeck, QList<Card*> &mainDeck);
    // Cделать ставку
    virtual int Parlay(Table *t);
};

#endif // AI_H
