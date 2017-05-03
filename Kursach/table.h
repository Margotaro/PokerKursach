#ifndef TABLE_H
#define TABLE_H
#include "ai.h"
#include "carddesk.h"
#include "you.h"
#include "mainwindow.h"
#include "player.h"
#include <QList>
#include <vector>
#include <QLabel>

class AI;
class You;
class Player;

class Table
{
    QList<Card*> CommunityCards;
    int Pot;
    vector<int> bets;

public:

    AI* firstCat;
    AI* secondCat;
    AI* thirdCat;
    AI* fourthCat;
    You* mainPlayer;
    // cs - количество фишек у каждого
    Table(int cs = 5000);
    QList<Card *> getCommunityCards();
    void addToCommunityCards(Card* card);
    int getPot();
    void putInPot(int cs[]);
    void giveaPotToWinner(Player* player);
    void makeaBet();
    bool callCheck();
    void leaveTheGame(int player);
    MainWindow* mainWindow;
    QList<Player*> players;
};

#endif // TABLE_H
