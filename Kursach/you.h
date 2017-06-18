#ifndef YOU_H
#define YOU_H
#include "player.h"
#include <QLabel>
#include <QEventLoop>
#include "table.h"
#include <iostream>

class Table;
class Player;

class You : public Player
{
    Q_OBJECT

    static You* instance;
    static int howManyCardsDoYouHaveRightNow;
    int yourDecision;
    int sliderVariable;
    void setActiveForButtons(bool isActive);
    bool firstBetDone;
public:
    You(int cs = 0);
    virtual void TakeaCard(Card* card);
    virtual int Parlay(Table *t);
    static void dropCards();
    static You* getInstance();
    QEventLoop* loop;
public slots:
    void YouRaise();
    void YouCheck();
    void YouCall();
    void YouFold();
    void YouAllIn();
    void sliderValueChanged(int value);
};

#endif // YOU_H
