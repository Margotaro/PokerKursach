#ifndef SET_H
#define SET_H
#include "card.h"
#include "combination.h"

class Set : public Combination
{
public:
    Set(Rank t3KindCard);
    Rank getRankOfCard();
    virtual int compareTo(Combination *c);
private:
    Rank ThreeKindCard;
};


#endif // SET_H
