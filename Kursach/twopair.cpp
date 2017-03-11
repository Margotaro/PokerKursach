#include "twopair.h"

TwoPair::TwoPair(Rank tFirstRank, Rank tSecondRank)
{
    if(tFirstRank > tSecondRank)
    {
        MaxRank = tFirstRank;
    }
    else
    {
        MaxRank = tSecondRank;
     }
    value = 14;
}

Rank TwoPair::getMaxRankOfCard()
{
    return MaxRank;
}

bool TwoPair::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return true;
    if(c->getValue() > value)
        return false;
    if(MaxRank > ((TwoPair*)c)->getMaxRankOfCard())
        return true;
    return false;
}
