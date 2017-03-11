#include "fullhouse.h"

FullHouse::FullHouse(Card *tKindOfSet, Card *tKindOfPair)
{
    FullSet = tKindOfSet->getRank();
    FullPair = tKindOfPair->getRank();
    value = 17;
}

Rank FullHouse::getRankOfPair()
{
    return FullPair;
}

Rank FullHouse::getRankOfSet()
{
    return FullSet;
}

bool FullHouse::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return true;
    if(c->getValue() > value)
        return false;
    if(FullSet != ((FullHouse*)c)->getRankOfSet())
        return FullSet > ((FullHouse*)c)->getRankOfSet();
    return FullPair > ((FullHouse*)c)->getRankOfPair();
}
