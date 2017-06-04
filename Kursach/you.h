#ifndef YOU_H
#define YOU_H
#include "player.h"
#include <QLabel>
#include <QEventLoop>
#include "table.h"
#include <iostream>

class Table;

class You : public Player
{
    Q_OBJECT

    static You* instance;
    int yourDecision;
    void setActiveForButtons(bool isActive);
public:
    You(int cs = 0);
    virtual void TakeaCard(Card* card);
    virtual int Parlay(Table *t);
    static You* getInstance();
    QEventLoop* loop;
public slots:
    void YouRaise();
    void YouCheck();
    void YouCall();
    void YouFold();
    void YouAllIn();
};

#endif // YOU_H
