#ifndef GAME_H
#define GAME_H
#include "table.h"
#include "carddesk.h"
#include "player.h"
#include "detectcombination.h"
#include "combination.h"
#include <QList>

#include <iostream>

using namespace std;

class Table;
class Player;

class Game
{
private:
    static Table* table;
    static CardDesk* carddesk;
    static QList<Combination* > playerCombinations;
    static int numofcommunitycards;
public:
    Game();
    static Table* getTable();
    static void Play();
    static void Bidding(int numofcards);
    static void Round();
    static QList<Player* > activePlayers;
};

#endif // GAME_H
