#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "card.h"
#include "combination.h"

class Straight : public Combination
{
public:
    Straight(Rank tFemale);
    Rank getHighestCard();
    virtual bool compareTo(Combination *c);
private:
    Rank female;
    int value;
};

#endif // STRAIGHT_H
