#ifndef STRAIGTFLUSH_H
#define STRAIGHTFLUSH_H

#include "card.h"
#include "combination.h"

class StraightFlush : public Combination
{
public:
    StraightFlush(Card* tHighestCard);
    Card* getHighestCard();
    virtual bool compareTo(Combination *c);
private:
    Card* highestCard;
    int value;
};

#endif // STRAIGHTFLUSH_H
