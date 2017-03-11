#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QString>

enum Suit {SNONE = 0, DIAMONDS = 1, HEARTS = 2, SPADES = 3, CLUBS = 4};
enum Rank {RNONE = 0, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13, ACE = 14};

class Card
{
private:
    Suit m_suit;
    Rank m_rank;
    bool result;
    
public:
    Card();
    Card(Suit tsuit, Rank trank);
    void setSuit(Suit tsuit);
    Suit getSuit();
    void setRank(Rank trank);
    Rank getRank();
};

#endif // CARD_H
