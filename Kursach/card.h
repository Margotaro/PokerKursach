#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QString>
#include <iostream>
#include <QPixmap>
#include <string>

enum Suit {SNONE = 0, DIAMONDS = 1, HEARTS = 2, SPADES = 3, CLUBS = 4};
enum Rank {RNONE = 0, TWO = 1, THREE = 2, FOUR = 3, FIVE = 4, SIX = 5, SEVEN = 6, EIGHT = 7, NINE = 8, TEN = 9, JACK = 10, QUEEN = 11, KING = 12, ACE = 13};

using namespace std;

class Card
{
private:
    Suit m_suit;
    Rank m_rank;
    bool result;
    QPixmap pixure;
    
public:
    Card();
    Card(Suit tsuit, Rank trank);
    void setSuit(Suit tsuit);
    Suit getSuit() const;
    void setRank(Rank trank);
    Rank getRank() const;
    QPixmap getCardFace() const;
    string ToString() const;

    friend bool operator ==(const Card& lCard, const Card& rCard);
    friend std::ostream& operator <<(std::ostream &os, const Card &c);
};

#endif // CARD_H
