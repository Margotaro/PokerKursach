#include "set.h"

Set::Set(Rank t3KindCard)
{
    ThreeKindCard = t3KindCard;
    value = 13;
}

Rank Set::getRankOfCard()
{
    return ThreeKindCard;
}

int Set::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    if(c->getValue() > value)
        return -1;
    else if(ThreeKindCard > ((Set*)c)->getRankOfCard())
        return 1;
    else if(ThreeKindCard == ((Set*)c)->getRankOfCard())
        return 0;
    return -1;
}
