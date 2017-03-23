#ifndef FLUSH_H
#define FLUSH_H

#include "combination.h"
#include "card.h"
#include "fullhouse.h"
#include <QList>
#include <QtAlgorithms>

class Flush : public Combination
{
public:
    Flush(QList<Card*> tFlush);
    QList<Card*> getCards();
    virtual int compareTo(Combination *c);
    bool compareCards(Card *c1, Card *c2);
private:
    QList<Card*> flush;
    int value;

};

#endif // FLUSH_H
