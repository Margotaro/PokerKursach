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
    value = 12;
}

Rank TwoPair::getMaxRankOfCard()
{
    return MaxRank;
}

int TwoPair::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    else if(c->getValue() > value)
        return -1;
    else if(MaxRank > ((TwoPair*)c)->getMaxRankOfCard())
        return 1;
    else if(MaxRank == ((TwoPair*)c)->getMaxRankOfCard())
        return 0;
    return -1;
}
