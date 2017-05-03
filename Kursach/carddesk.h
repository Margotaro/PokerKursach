#ifndef CARDDESK_H
#define CARDDESK_H
#include <QList>
#include "card.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <QString>

class CardDesk
{
    QList<Card *> Deck;

private:
    void putCard(Card* const &crd);
public:
    Card* giveTopCard();
    CardDesk();
    CardDesk(QList<Card*> deck);
    QList<Card*> getDeck() const;
    void shuffle();
    void fill();
    void clear();
    int length();
    friend std::ostream& operator <<(std::ostream &os, const CardDesk &cd);
    friend CardDesk& operator <<(CardDesk &ds, Card* const &crd);
};


#endif // CARDDESK_H
