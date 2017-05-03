#ifndef PLAYER_H
#define PLAYER_H
#include "carddesk.h"
#include <QLabel>
#include <string>
#include "game.h"

class Table;
class Game;

class Player
{
protected:

    int ChipStack;
    CardDesk desk;
    static int minimumBet;//минимальная ставка
    bool outOfGame;
    bool outOfRound;

    //    Place
    //    0 - игрок
    //    1 - крайний слева котик
    //    2 - второй слева котик
    //    3 - третий
    //    4 - четвертый соответственно
    int Place;

public:

    virtual void TakeaCard(Card* card) = 0;
    virtual void Parlay(Table* table) = 0;
    bool isOutOfGame();
    bool isOutOfRound();
    int Raise(int chips);
    int Check();
    int Call();
    int Fold();
    int AllIn();
    void switchRound();
    void takeaPot(int cs);
    int makeaBet(int b);
    Player(int cs = 0);
};

#endif // PLAYER_H
