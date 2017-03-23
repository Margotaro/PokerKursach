#include "fourofakind.h"
#include "card.h"
#include <iostream>


FourOfaKind::FourOfaKind()
{
    value = 17;
}

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
    std::cout << "Program has been here" << std::endl;
    std::cout << "Value c: " << c->getValue()<< std::endl;
    std::cout << "Value this:" << value << std::endl;

    std::cout << "((FourOfaKind*)c)->getRankOfCard()) :" << (((FourOfaKind*)c)->getRankOfCard()) << std::endl;
    std::cout << "The highest out of four(this):" << FourKindCard << std::endl;

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
