#include "fourofakind.h"
#include "card.h"

FourOfaKind::FourOfaKind(Card* t4KindCard)
{
    FourKindCard = t4KindCard->getRank();
    value = 18;
}

Rank FourOfaKind::getRankOfCard()
{
    return FourKindCard;
}

bool FourOfaKind::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return true;
    if(c->getValue() > value)
        return false;
    return FourKindCard > ((FourOfaKind*)c)->getRankOfCard();
}
