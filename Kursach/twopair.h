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
};

#endif // TWOPAIR_H
