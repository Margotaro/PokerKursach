#ifndef GAME_H
#define GAME_H
#include "table.h"
#include "carddesk.h"
#include "player.h"

class Player;

class Game
{
    static int BigBlind;
    Table* table;
    CardDesk* carddesk;
    QList<Player* > activePlayers;
public:
    Game();
    void Play();
    void Bidding(int numofcards);
};

#endif // GAME_H
