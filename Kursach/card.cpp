#include "card.h"

using namespace std;

Card::Card()
{
    m_suit = SNONE;
    m_rank = RNONE;
}

Card::Card(Suit tsuit, Rank trank)
{
    m_suit = tsuit;
    m_rank = trank;

    QString suits = "DHSC";
    QString tPngName = "C:\\Users\\Margotaro\\Desktop\\REPOSITORY\\PokerKursach\\PekorCards\\" + suits[tsuit-1] + QString::number(trank+1) + ".png";
    picture = new QPixmap();
    picture->load(tPngName);
}

void Card::setSuit(Suit tsuit)
{
    m_suit = tsuit;
}

Suit Card::getSuit() const
{
    return m_suit;
}

void Card::setRank(Rank trank)
{
    m_rank = trank;
}

Rank Card::getRank() const
{
    return m_rank;
}

string Card::ToString() const
{
    return "Suit: " + QString::number(m_suit).toStdString() + "Rank: " + QString::number(m_rank).toStdString();
}

bool operator ==(const Card& lCard, const Card& rCard)
{
    return ((lCard.getRank() == rCard.getRank())&&(lCard.getSuit() == rCard.getSuit()));
}

ostream& operator <<(ostream &os, const Card &c)
{
    int i = (int)c.getSuit();
    switch(i)
        {
            case DIAMONDS:
                os << i+1 << ": DIAMONDS ";
                break;
            case HEARTS:
                os << i+1 << ": HEARTS ";
                break;
            case SPADES:
                os << i+1 << ": SPADES ";
                break;
            case CLUBS:
                os << i+1 << ": CLUBS ";
                break;
        }
    i = (int)c.getRank();
    switch(i)
        {
            case TWO:
                os << i+1 << ", DIAMONDS; " << endl;
                break;
            case THREE:
                os << i+1 << ", HEARTS; " << endl;
                break;
            case FOUR:
                os << i+1 << ", SPADES; " << endl;
                break;
            case FIVE:
                os << i+1 << ", CLUBS; " << endl;
                break;

            case SIX:
                os << i+1 << ", SIX; " << endl;
                break;
            case SEVEN:
                os << i+1 << ", SEVEN; " << endl;
                break;
            case EIGHT:
                os << i+1 << ", EIGHT; " << endl;
                break;
            case NINE:
                os << i+1 << ", NINE; " << endl;
                break;

            case TEN:
                os << i+1 << ", TEN; " << endl;
                break;
            case JACK:
                os << i+1 << ", JACK; " << endl;
                break;
            case QUEEN:
                os << i+1 << ", QUEEN; " << endl;
                break;
            case KING:
                os << i+1 << ", KING; " << endl;
                break;
            case ACE:
                os << i+1 << ", ACE; " << endl;
                break;
        }
     return os;
}

QPixmap* Card::getCardFace() const
{
    return picture;
}
