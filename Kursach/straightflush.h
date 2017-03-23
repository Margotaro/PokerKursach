#ifndef STRAIGHTFLUSH_H
#define STRAIGHTFLUSH_H

#include "card.h"
#include "combination.h"

class StraightFlush : public Combination
{
public:
    StraightFlush(Rank tHighestCard);
    Rank getHighestCard();
    virtual int compareTo(Combination *c);
    int getValue();
private:
    Rank highestCard;
    int value;
};

#endif // STRAIGHTFLUSH_H
