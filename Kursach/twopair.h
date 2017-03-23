#ifndef TWOPAIR_H
#define TWOPAIR_H
#include "card.h"
#include "combination.h"

class TwoPair : public Combination
{
public:
    TwoPair(Rank tFirstRank, Rank tSecondRank);
    Rank getMaxRankOfCard();
    virtual int compareTo(Combination *c);
private:
    Rank MaxRank;
    int value;
};

#endif // TWOPAIR_H
