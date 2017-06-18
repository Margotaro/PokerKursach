#include "table.h"

Table::Table(int cs)
{

    Pot = 0;

    firstCat = new AI(cs);
    firstCat->setLabelName(Name::FirstCat);
    secondCat = new AI(cs);
    secondCat->setLabelName(Name::SecondCat);
    thirdCat = new AI(cs);
    thirdCat->setLabelName(Name::ThirdCat);
    fourthCat = new AI(cs);
    fourthCat->setLabelName(Name::FourthCat);
    mainPlayer = new You(cs);
    mainPlayer->setLabelName(Name::YourCat);

    players << firstCat;
    players << secondCat;
    players << thirdCat;
    players << fourthCat;
    players << mainPlayer;
}

void Table::addToCommunityCards(Card* card)
{
    CommunityCards << card;
    //QLabel* label = new QLabel(MainWindow::getInstance());
    //label->setGeometry(CommunityCards.length() * 110, 180 , 100, 160);
    //label->setPixmap(card->getCardFace());
}

QList<Card *> Table::getCommunityCards()
{
    return CommunityCards;
}

void Table::refreshPlayersInfo()
{
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i]->isOutOfGame())
            MainWindow::getInstance()->getCatBetLabel(players[i]->getLabelName())->setText("left");
        else
            if(players[i]->isOutOfRound())
                MainWindow::getInstance()->getCatBetLabel(players[i]->getLabelName())->setText("folded");
            else
                MainWindow::getInstance()->getCatBetLabel(players[i]->getLabelName())->setText("0");
    }
}

void Table::printTable()
{
    cout << endl << "---" << "Pot: " << Pot << endl;

    for(int i = 0; i < players.size(); i++)
    {
        cout << "Player " << i << "Chipstack: " << players[i]->getChipStack() << endl;
    }

    cout << "---" << endl;
}

int Table::getPot()
{
    return Pot;
}

void Table::putBetsInPot()
{
    for (int i = 0; i < players.size(); i++) {
        Pot += players[i]->Bet;
        players[i]->Bet = 0;
    }
    cout << endl << "BETS ARE PUT. NOW POT IS " << Pot << endl;
}

void Table::giveaPotToWinner(Player *player, int numofwinners)
{
    int tPot = Pot;
    Pot = 0;
    player->takeaPot(tPot/numofwinners);
}

bool Table::callCheck()
{
        int mainIndex;
        for(int i = 0; i < players.size() - 1; i++)
        {
            if(!players[i]->isOutOfRound())
            {
                mainIndex = i;
                break;
            }
        }
        for(int i = mainIndex + 1; i < players.size(); i++)
        if((players[mainIndex]->Bet != players[i]->Bet)&&(!players[i]->isOutOfRound())&&(players[i]->Bet != 0))
            return false;
    return true;
}

void Table::leaveTheGame(int player)
{
    players.removeAt(player);
}

void Table::putaBet(int i, int chips)
{
    players[i]->Bet += chips;

}
