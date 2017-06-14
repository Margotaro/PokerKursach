#include "game.h"
#include <cassert>

QList<Player*> Game::activePlayers = QList<Player*>();
CardDesk* Game::carddesk = new CardDesk();
Table* Game::table = new Table(2000);
QList<Combination*> Game::playerCombinations = QList<Combination*>();
int Game::numofcommunitycards = 0;

Game::Game()
{
}

void Game::Play()
{
 //   while(table->players.size() > 1)
        Round();
}

void Game::Round()
{

    activePlayers = table->players;


    numofcommunitycards = 0;
    carddesk->fill();
    carddesk->shuffle();


    for (int i = 0; i < activePlayers.size(); i++)
    {
        activePlayers[i]->TakeaCard(carddesk->giveTopCard());
        activePlayers[i]->TakeaCard(carddesk->giveTopCard());
    }

    assert (table->players.size() >= 2);

    int last = activePlayers.size() - 1;
    int BB = activePlayers[last - 1]->makeaBigBlind();
    MainWindow::getInstance()->changeCatBetBox(activePlayers[last - 1], BB);
    int SB = activePlayers[last]->makeaSmallBlind();
    MainWindow::getInstance()->changeCatBetBox(activePlayers[last], SB);

    Bidding(0);
    Bidding(3);
    Bidding(1);
    Bidding(1);

    QList<int> roundWinner;
    roundWinner.push_back(0);
    for(int i = 0; i < activePlayers.size(); i++)
    {
        playerCombinations.push_back(nullptr);
        QList<Card* > pc = activePlayers[i]->getTwoCards() + table->getCommunityCards();
        playerCombinations[i] = DetectCombination::Detect(pc);
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
    {
        table->giveaPotToWinner(activePlayers[roundWinner[i]], roundWinner.size());
        MainWindow::getInstance()->win(activePlayers[roundWinner[i]]);
    }

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
  if(activePlayers.size() == 1)
      return;
  for (int i = 0; i < numofcards; i++)
  {
        table->addToCommunityCards(carddesk->giveTopCard());
        MainWindow::getInstance()->showCommunityCard(numofcommunitycards);
        numofcommunitycards++;
  }

  for(int j = 0 ; j < 2; j++)
  {
        for (int i = 0; (i < activePlayers.size())&&(activePlayers.size() > 1) ; i++ )
        {
            int tBet = (activePlayers[i])->Parlay(table);
            MainWindow::getInstance()->changeCatBetBox(activePlayers[i], tBet);

            if(tBet == -1)
            {
                activePlayers.removeAt(i);
                i--;
            }

            else
            {
                table->putaBet(i, tBet);
            }

        }
  }

  table->putBetsInPot();
  MainWindow::getInstance()->changePot(table->getPot());
    for(int i = 0; i < table->players.size(); i++)
    {
//        table->players[i]->switchBidding();
    }

}
