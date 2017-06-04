#ifndef PLAYER_H
#define PLAYER_H
#include "carddesk.h"
#include <QLabel>
#include <QObject>
#include <string>

class Table;

class Player : public QObject
{
    Q_OBJECT
protected:
    int id;
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
    string name;//cut it
    static int BigBlind;

    int Raise(int chips);
    int Check();
    int Call();
    int Fold();
    int AllIn();

public:
    static int getMinimumBet();
    virtual void TakeaCard(Card* card) = 0;
    virtual int Parlay(Table* table) = 0;
    bool isOutOfGame();
    bool isOutOfRound();
    int getChipStack();
    QList<Card* > getTwoCards();
    int makeaBigBlind();
    int makeaSmallBlind();
    void setaMinimumBet(int minBet);
    void switchRound();
    void takeaPot(int cs);
    Player(int cs = 0);
    void setname(string name);//cut it
    string showname();//cut it
    int Bet;
};

#endif // PLAYER_H
