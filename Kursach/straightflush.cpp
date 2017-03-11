#include "straightflush.h"


StraightFlush::StraightFlush(Card* tHighestCard)
{
    highestCard = tHighestCard;
    value = 19;
}

Card* StraightFlush::getHighestCard()
{
    return highestCard;
}

bool StraightFlush::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return true;
    if(c->getValue() > value)
        return false;
    return highestCard->getRank() > ((StraightFlush*)c)->getHighestCard()->getRank();
}
