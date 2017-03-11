#ifndef FULLHOUSE_H
#define FULLHOUSE_H

#include "card.h"
#include "combination.h"

class FullHouse : public Combination
{
public:
    FullHouse(Card* tKindOfSet, Card* tKindOfPair);
    Rank getRankOfSet();
    Rank getRankOfPair();
    virtual bool compareTo(Combination *c);
private:
    Rank FullSet;
    Rank FullPair;


    int value;
};

#endif // FULLHOUSE_H
