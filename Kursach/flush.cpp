#include "flush.h"

Flush::Flush(QList<Card*> tFlush)
{
    flush = tFlush;
    qSort(flush.begin(), flush.end(), compareCards);
    value = 16;
}

bool compareCards(Card* c1, Card* c2)
{
    return c1->getRank() > c2->getRank();
}

QList<Card*> Flush::getCards()
{
    return flush;
}

bool Flush::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return true;
    if(c->getValue() > value)
        return false;
    for(int i = 0; i < 5; i++)
        if(((Flush*)c)->getCards()[i]->getRank() < flush[i]->getRank())
            return true;
    return false;
}
