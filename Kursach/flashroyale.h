#ifndef FLASHROYALE_H
#define FLASHROYALE_H

#include "combination.h"
#include <QList>

class FlashRoyale : private Combination
{
public:
    FlashRoyale();
    virtual bool compareTo(Combination *c);
private:
    int value;
};

#endif // FLASHROYALE_H
