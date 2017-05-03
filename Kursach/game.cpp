#include "game.h"

int Game::BigBlind = 20;

Game::Game()
{
    table = new Table(5000);
    carddesk = new CardDesk();
}

void Game::Play()
{
    //Preflop
    carddesk->fill();
    carddesk->shuffle();

    for (int i = 0; i < activePlayers.size(); i++)
    {
        activePlayers[i]->TakeaCard(carddesk->giveTopCard());
        activePlayers[i]->TakeaCard(carddesk->giveTopCard());
    }

}

void Game::Bidding(int numofcards)
{
    activePlayers = table->players;

    //Blinds
    activePlayers[0]->makeaBet(BigBlind);
    activePlayers[1]->makeaBet(BigBlind/2);

    for (int i = 0; i < numofcards; i++)
        table->addToCommunityCards(carddesk->giveTopCard());

    int calls = 0;
    int folded = 0;

    for (int i = 0; calls != activePlayers; i = (i + 1)%5)
    {
        (activePlayers[i])->Parlay(table);
        if((activePlayers[i])->isOutOfGame())
           {
                table->leaveTheGame(i);
           }
        if(activePlayers[i]->isOutOfRound())
        {
            activePlayers.removeAt(i);
        }
    }

    Player* tmp;
    tmp = table->players[0];
    for (int i = 0; i < table->players.size() - 1; i++)
        table->players[i] = table->players[i+1];
    table->players[4] = tmp;
}
