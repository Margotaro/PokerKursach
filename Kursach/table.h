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
#include "game.h"
#include "mainwindow.h"
#include <iostream>

class AI;
class You;
class Player;
class MainWindow;

class Table
{
    QList<Card*> CommunityCards;
    int Pot;

public:

    AI* firstCat;
    AI* secondCat;
    AI* thirdCat;
    AI* fourthCat;
    You* mainPlayer;
    void refreshPlayersInfo();
    void printTable();
    // cs - количество фишек у каждого
    Table(int cs = 5000);
    QList<Card *> getCommunityCards();
    void addToCommunityCards(Card* card);
    int getPot();
    void putBetsInPot();
    void giveaPotToWinner(Player* player, int numofwinners);
    void putaBet(int i, int chips);
    bool callCheck();
    void leaveTheGame(int player);
    MainWindow* mainWindow;
    QList<Player*> players;
};

#endif // TABLE_H
