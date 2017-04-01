#include "highcard.h"
#include "detectcombination.h"

HighCard::HighCard(Rank theHighCard)
{
    MaxRank = theHighCard;
    value = 10;
}

int HighCard::getValue()
{
    return value;
}

Rank HighCard::getMaxRankOfCard()
{
    return MaxRank;
}

int HighCard::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    else if(c->getValue() > value)
        return -1;
    else if(MaxRank > ((HighCard*)c)->getMaxRankOfCard())
        return 1;
    else if(MaxRank == ((HighCard*)c)->getMaxRankOfCard())
        return 0;
    return -1;
}
