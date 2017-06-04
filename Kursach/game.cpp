#include "game.h"
#include <cassert>

QList<Player*> Game::activePlayers = QList<Player*>();
CardDesk* Game::carddesk = new CardDesk();
Table* Game::table = new Table(2000);
QList<Combination*> Game::playerCombinations = QList<Combination*>();

Game::Game()
{
}

void Game::Play()
{
//    while(table->players.size() > 1)
        Round();
}

void Game::Round()
{

    activePlayers = table->players;

    carddesk->fill();
    carddesk->shuffle();


    for (int i = 0; i < activePlayers.size(); i++)
    {
        activePlayers[i]->TakeaCard(carddesk->giveTopCard());
        activePlayers[i]->TakeaCard(carddesk->giveTopCard());
    }

    assert (table->players.size() >= 2);

    int last = activePlayers.size() - 1;
    int BB = activePlayers[0]->makeaBigBlind();
    cout << "Big Blind by " << activePlayers[last]->showname() << " is " << BB << endl;

    int SB = activePlayers[1]->makeaSmallBlind();
    cout << "Small Blind by " << activePlayers[last - 1]->showname() << " is " << SB << endl;

    Bidding(0);
    cout << "Total pot is: " << table->getPot() << endl;
    Bidding(3);
    cout << "Total pot is: " << table->getPot() << endl;
    Bidding(1);
    cout << "Total pot is: " << table->getPot() << endl;
    Bidding(1);
    cout << "Total pot is: " << table->getPot() << endl;

    QList<int> roundWinner;
    roundWinner.push_back(0);
    for(int i = 0; i < activePlayers.size(); i++)
    {
        playerCombinations.push_back(nullptr);
        QList<Card* > pc = activePlayers[i]->getTwoCards() + table->getCommunityCards();
        playerCombinations[i] = DetectCombination::Detect(pc);

        cout << "Im here!!!";
    }


    for(int i = 1; i < activePlayers.size(); i++)
    {
        if((playerCombinations[i]->compareTo(playerCombinations[i - 1])) == 1)
        {
            roundWinner.clear();
            roundWinner.push_back(i);
        }
        else if((playerCombinations[i]->compareTo(playerCombinations[i - 1])) == 0)
            roundWinner.push_back(i);
    }

    cout << endl << endl << "-------------------" << endl << "------------------" << endl
         << "GAME RESULTS" << endl << "--------------" << endl << "----------------" << endl << endl;

    cout << "Total pot is: " << table->getPot() << endl;

    for(int i = 0; i < roundWinner.size(); i++)
        table->giveaPotToWinner(activePlayers[roundWinner[i]], roundWinner.size());

    cout << "Round winners count is: " << roundWinner.size() << endl;
    cout << "Round winner's prize is: " << table->players[roundWinner[0]]->getChipStack() << endl;


    cout << endl << "______________________" << endl;
/*
    Player* tmp;
    tmp = table->players[0];
    for (int i = 0; i < 4; i++)
    {
        table->players[i] = table->players[i+1];
        table->players[i]->switchRound();
    }
    table->players[4] = tmp;
    table->players[4]->switchRound();
    */
}

Table* Game::getTable()
{
    return table;
}

void Game::Bidding(int numofcards)
{
    cout << endl << endl << "-----------------------" << endl <<  "NEW ROUND" << endl << "---------------------------" << endl << endl;

    for (int i = 0; i < numofcards; i++)
        table->addToCommunityCards(carddesk->giveTopCard());
//    int checks = 0;

//    for (int i = 2; (checks != activePlayers.size())||(activePlayers.size() == 1); i = (i + 1)%activePlayers.size())
  for(int j = 0 ; j < 2; j++)
  {
        for (int i = 0; (i < activePlayers.size())&&(activePlayers.size() > 1) ; i++ )
        {
            cout << "i is " << i << " and size is " << activePlayers.size();

            cout << endl << activePlayers[i]->showname() << ": " << endl;

            int tBet = (activePlayers[i])->Parlay(table);

            cout << "tBet is: " << tBet << endl;

            if(tBet == -1)
            {
                activePlayers.removeAt(i);
                i--;
            }

            //else if(tBet == 0)
            //    checks += 1;
            else
            {
                table->putaBet(i, tBet);
            }
            //if(i == 0)
            //    getchar();

        }
  }

  table->putBetsInPot();

}
