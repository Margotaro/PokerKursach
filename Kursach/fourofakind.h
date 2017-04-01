#ifndef FOUROFAKIND_H
#define FOUROFAKIND_H
#include "card.h"
#include "combination.h"

class FourOfaKind : public Combination
{
public:
    FourOfaKind::FourOfaKind() : Combination() { value = 17; }
    FourOfaKind(Rank t4KindCard);
    Rank getRankOfCard();
    virtual int compareTo(Combination *c);
private:
    Rank FourKindCard;
};

#endif // FOUROFAKIND_H
