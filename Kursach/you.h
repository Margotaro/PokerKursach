#ifndef YOU_H
#define YOU_H
#include "player.h"
#include <QLabel>
#include "table.h"

class Table;

class You : public Player
{
public:
    You(int cs = 0);
    virtual void TakeaCard(Card* card);
    virtual void Parlay(Table *t);
};

#endif // YOU_H
