#include "straight.h"

Straight::Straight(Rank tFemale)
{
    female = tFemale;
    value = 15;
}

Rank Straight::getHighestCard()
{
    return female;
}

bool Straight::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return true;
    if(c->getValue() > value)
        return false;
    return female > ((Straight*)c)->getHighestCard();
}
