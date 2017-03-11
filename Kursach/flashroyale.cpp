#include "flashroyale.h"

FlashRoyale::FlashRoyale()
{
    value = 20;
}

bool FlashRoyale::compareTo(Combination *c)
{
    return c->getValue() == value;
}
