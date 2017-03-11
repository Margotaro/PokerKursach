#include "onepair.h"

OnePair::OnePair(Rank tRank)
{
    rank = tRank;
    value = 13;
}

Rank OnePair::getRankOfCard()
{
    return rank;
}

bool OnePair::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return true;
    if(c->getValue() > value)
        return false;
    return Rank > ((OnePair*)c)->getRankOfCard();
}
