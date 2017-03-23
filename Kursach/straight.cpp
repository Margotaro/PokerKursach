#include "straight.h"

Straight::Straight(Rank tFemale)
{
    female = tFemale;
    value = 14;
}

Rank Straight::getHighestCard()
{
    return female;
}

int Straight::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    if(c->getValue() > value)
        return -1;
    else if(female > ((Straight*)c)->getHighestCard())
        return 1;
    else if(female == ((Straight*)c)->getHighestCard())
        return 0;
    return -1;
}
