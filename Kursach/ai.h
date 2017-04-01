#ifndef AI_H
#define AI_H
#include<QList>
#include <iostream>
#include "card.h"
#include "detectcombination.h"

class AI
{
public:
    AI();
    float BrutForce(QList<Card*> myDeck, QList<Card*> mainDeck);
};

#endif // AI_H
