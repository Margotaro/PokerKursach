#ifndef PLAYER_H
#define PLAYER_H
#include "carddesk.h"
#include <QLabel>
#include <QObject>
#include <QString>
#include "mainwindow.h"

class Table;

enum Name { FirstCat = 0, SecondCat = 1, ThirdCat = 2, FourthCat = 3, YourCat = 4};

class Player : public QObject
{
    Q_OBJECT
protected:
    int ChipStack;
    CardDesk desk;
    static int minimumBet;
    bool outOfGame;
    bool outOfRound;

    //    Place
    //    0 - игрок
    //    1 - крайний слева котик
    //    2 - второй слева котик
    //    3 - третий
    //    4 - четвертый соответственно
    int Place;
    Name playerID;
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
//    void switchBidding();
    void takeaPot(int cs);
    Player(int cs = 0);
    void setLabelName(Name id);
    Name getLabelName();
    int Bet;
};

#endif // PLAYER_H
