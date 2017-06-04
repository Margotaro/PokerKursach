#include "table.h"

Table::Table(int cs)
{

    Pot = 0;

    firstCat = new AI(cs);
    secondCat = new AI(cs);
    thirdCat = new AI(cs);
    fourthCat = new AI(cs);
    mainPlayer = new You(cs);

    firstCat->setname("first kitten");
    secondCat->setname("second kitten");
    thirdCat->setname("third kitten");
    fourthCat->setname("fourth kitten");
    mainPlayer->setname("you");

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
    for(int i = 0; i < players.size() - 1; i++)
        if((players[i]->Bet != players[i + 1]->Bet)&&(!players[i]->isOutOfRound())&&(!players[i + 1]->isOutOfRound()))
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
