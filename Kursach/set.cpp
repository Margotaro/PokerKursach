#include "set.h"
#include "card.h"

Set::ThreeOfaKind(Rank t3KindCard)
{
    ThreeKindCard = t3KindCard;
    value = 14;
}

Rank Set::getRankOfCard()
{
    return ThreeKindCard;
}

bool Set::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return true;
    if(c->getValue() > value)
        return false;
    return ThreeKindCard > ((Set*)c)->getRankOfCard();
}
