#include "flashroyale.h"

FlashRoyale::FlashRoyale()
{
    value = 19;
}

int FlashRoyale::compareTo(Combination *c)
{
    if (c->getValue() == value)
        return 0;
    else return 1;
}
