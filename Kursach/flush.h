#ifndef FLUSH_H
#define FLUSH_H

#include "combination.h"
#include "card.h"
#include "fullhouse.h"
#include <QList>

class Flush : public Combination
{
public:
    Flush(QList<Card*> tFlush);
    QList<Card*> getCards();
    virtual bool compareTo(Combination *c);
private:
    QList<Card*> flush;
    int value;

};

#endif // FLUSH_H
