#include "fourofakind.h"
#include "card.h"
#include "detectcombination.h"
#include <iostream>


FourOfaKind::FourOfaKind(Rank t4KindCard)
{
    FourKindCard = t4KindCard;
    value = 17;
}

Rank FourOfaKind::getRankOfCard()
{
    return FourKindCard;
}

int FourOfaKind::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    else if(c->getValue() > value)
        return -1;
    else if(FourKindCard > ((FourOfaKind*)c)->getRankOfCard())
        return 1;
    else if(FourKindCard == ((FourOfaKind*)c)->getRankOfCard())
        return 0;
    return -1;
}
