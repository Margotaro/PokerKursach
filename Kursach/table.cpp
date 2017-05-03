#include "table.h"

Table::Table(int cs)
{
    bets.resize(5, 0);
    Pot = 0;

    firstCat = new AI(cs);
    secondCat = new AI(cs);
    thirdCat = new AI(cs);
    fourthCat = new AI(cs);
    mainPlayer = new You(cs);

    players << firstCat;
    players << secondCat;
    players << thirdCat;
    players << fourthCat;
    players << mainPlayer;
}

void Table::addToCommunityCards(Card* card)
{
    CommunityCards << card;
    QLabel* label = new QLabel(MainWindow::getInstance());
    label->setGeometry(CommunityCards.length() * 110, 180 , 100, 160);
    label->setPixmap(card->getCardFace());
}

QList<Card *> Table::getCommunityCards()
{
    return CommunityCards;
}

int Table::getPot()
{
    return Pot;
}

void Table::putInPot(int cs[])
{
    for (int i = 0; i < 5; i++)
        Pot += cs[i];
}

void Table::giveaPotToWinner(Player *player)
{
    int tPot = Pot;
    Pot = 0;
    player->takeaPot(tPot);
}

bool Table::callCheck()
{
    for(int i = 0; i < bets.size() - 1; i++)
        if(bets[i] != bets[i + 1])
            return false;
    return true;
}

void Table::leaveTheGame(int player)
{
    players.removeAt(player);
}
