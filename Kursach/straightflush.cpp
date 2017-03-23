#include "straightflush.h"

StraightFlush::StraightFlush(Rank tHighestCard)
{
    highestCard = tHighestCard;
    value = 18;
}

int StraightFlush::getValue()
{
    return value;
}

Rank StraightFlush::getHighestCard()
{
    return highestCard;
}

int StraightFlush::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    else if(c->getValue() > value)
        return -1;
    else if(highestCard > ((StraightFlush*)c)->getHighestCard())
        return 1;
    else if(highestCard == ((StraightFlush*)c)->getHighestCard())
        return 0;
    return -1;
}
