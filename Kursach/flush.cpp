#include "flush.h"
#include "detectcombination.h"

Flush::Flush(QList<Card*> tFlush)
{
    flush = tFlush;
    qSort(flush.begin(), flush.end(), [](Card* c1, Card* c2) -> bool { return c1->getRank() > c2->getRank(); });
    value = 15;
}

QList<Card*> Flush::getCards()
{
    return flush;
}

int Flush::compareTo(Combination *c)
{
    if(c->getValue() < value)
        return 1;
    if(c->getValue() > value)
        return -1;
    for(int i = 0; i < 5; i++)
        if(((Flush*)c)->getCards()[i]->getRank() < flush[i]->getRank())
            return 1;
        else if(((Flush*)c)->getCards()[i]->getRank() == flush[i]->getRank())
            return 0;
    return -1;
}
