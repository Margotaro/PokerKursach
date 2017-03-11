#ifndef DETECTCOMBINATION_H
#define DETECTCOMBINATION_H

#include "combination.h"
#include "flashroyale.h"
#include "card.h"

class DetectCombination
{
public:
    DetectCombination();
    Combination* Detect(QList<Card*> cards);

};

#endif // DETECTCOMBINATION_H
