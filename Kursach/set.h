#ifndef SET_H
#define SET_H
#include "card.h"
#include "combination.h"

class Set : public Combination
{
public:
    Set(Rank t3KindCard);
    Rank getRankOfCard();
    virtual bool compareTo(Combination *c);
private:
    Rank ThreeKindCard;
    int value;
};


#endif // SET_H
