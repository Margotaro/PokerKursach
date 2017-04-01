#ifndef FLASHROYALE_H
#define FLASHROYALE_H

#include "combination.h"
#include "card.h"
#include <QList>

class FlashRoyale : public Combination
{
public:
    FlashRoyale();
    virtual int compareTo(Combination* c);
};

#endif // FLASHROYALE_H
