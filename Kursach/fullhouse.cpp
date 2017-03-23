#include "fullhouse.h"

FullHouse::FullHouse(Rank tKindOfSet, Rank tKindOfPair)
{
    FullSet = tKindOfSet;
    FullPair = tKindOfPair;
    value = 16;
}

Rank FullHouse::getRankOfPair()
{
    return FullPair;
}

Rank FullHouse::getRankOfSet()
{
    return FullSet;
}

int FullHouse::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    if(c->getValue() > value)
        return -1;
    if(FullSet != ((FullHouse*)c)->getRankOfSet())
    {
        if(FullSet > ((FullHouse*)c)->getRankOfSet())
            return 1;
        else if(FullSet == ((FullHouse*)c)->getRankOfSet())
            return 0;
        return -1;
    }

    if(FullPair > ((FullHouse*)c)->getRankOfPair())
            return 1;
    else if(FullPair == ((FullHouse*)c)->getRankOfPair())
            return 0;
        return -1;
}
