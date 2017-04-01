#ifndef FULLHOUSE_H
#define FULLHOUSE_H

#include "card.h"
#include "combination.h"

class FullHouse : public Combination
{
public:
    FullHouse(Rank tKindOfSet, Rank tKindOfPair);
    Rank getRankOfSet();
    Rank getRankOfPair();
    virtual int compareTo(Combination *c);
private:
    Rank FullSet;
    Rank FullPair;
};

#endif // FULLHOUSE_H
