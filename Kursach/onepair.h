#ifndef ONEPAIR_H
#define ONEPAIR_H
#include "card.h"
#include "combination.h"

class OnePair : public Combination
{
public:
    OnePair(Rank tRank);
    Rank getRankOfCard();

    virtual bool compareTo(Combination *c);
private:
    Rank rank;
    int value;
};

#endif // ONEPAIR_H
