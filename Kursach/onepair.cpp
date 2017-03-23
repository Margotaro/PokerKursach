#include "onepair.h"

OnePair::OnePair(Rank tRank)
{
    rank = tRank;
    value = 11;
}

Rank OnePair::getRankOfCard()
{
    return rank;
}

int OnePair::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    if(c->getValue() > value)
        return -1;
    else if(rank > ((OnePair*)c)->getRankOfCard())
        return 1;
    else if(rank == ((OnePair*)c)->getRankOfCard())
        return 0;
    return -1;
}
