#include "you.h"

You::You(int cs) : Player(cs)
{
    Place = 0;
}

void You::TakeaCard(Card* card)
{
    desk << card;
    QLabel* label = new QLabel(MainWindow::getInstance());
    label->setGeometry(0,0,100, 160);
    label->setPixmap(card->getCardFace());
}

void You::Parlay(Table *t)
{

}
