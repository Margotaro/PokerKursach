#ifndef FOUROFAKIND_H
#define FOUROFAKIND_H
#include "card.h"
#include "combination.h"

class FourOfaKind : public Combination
{
public:
    FourOfaKind(Card* t4KindCard);
    Rank getRankOfCard();
    virtual bool compareTo(Combination *c);
private:
    Rank FourKindCard;
    int value;
};

#endif // FOUROFAKIND_H
