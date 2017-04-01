#ifndef HIGHCARD_H
#define HIGHCARD_H
#include "card.h"
#include "combination.h"

class HighCard : public Combination
{
public:
    HighCard(Rank theHighCard);
    int getValue();
    Rank getMaxRankOfCard();
    virtual int compareTo(Combination *c);
private:
    Rank MaxRank;
};

#endif // HIGHCARD_H
