#ifndef FLASHROYALE_H
#define FLASHROYALE_H

#include "combination.h"
#include <QList>

class FlashRoyale : public Combination
{
public:
    FlashRoyale();
    virtual int compareTo(Combination *c);
private:
    int value;
};

#endif // FLASHROYALE_H
