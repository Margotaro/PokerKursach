#include "carddesk.h"
#include "time.h"

using namespace std;

CardDesk::CardDesk()
{

}

QList<Card *> CardDesk::getDeck() const
{
    return Deck;
}

CardDesk::CardDesk(QList<Card*> deck)
{
    Deck = deck;
}

void CardDesk::shuffle()
{
    srand(time(0));
    std::random_shuffle(Deck.begin(), Deck.end());
}

int CardDesk::length()
{
    return Deck.length();
}

Card* CardDesk::giveTopCard()
{
    if(Deck.isEmpty())
    {
        return nullptr;
    }
    Card* tCard = Deck.front();
    Deck.pop_front();
    return tCard;
}

void CardDesk::fill()
{

    if(!(Deck.isEmpty()))
            Deck.clear();

    cout << "INIT BEGINS" << endl;

    for(int s = DIAMONDS; s <=CLUBS; s++)
    {
        for(int r = TWO; r <=ACE; r++)
        {
            Deck << new Card((Suit)s, (Rank)r);
        }
    }
    cout << "INIT ENDS" << endl;
}

void CardDesk::clear()
{
    Deck.clear();
}

ostream& operator <<(ostream &os, const CardDesk &cd)
{
    QList<Card*> carddeck = cd.getDeck();
        for(int i = 0; i < carddeck.length(); i++)
        {
            switch((carddeck[i])->getSuit())
            {
                case DIAMONDS: os << i+1 << ": DIAMONDS ";
                break;
                case HEARTS: os << i+1 << ": HEARTS ";
                break;
                case SPADES: os << i+1 << ": SPADES ";
                break;
                case CLUBS: os << i+1 << ": CLUBS ";
                break;
            }
            switch((carddeck[i])->getRank())
            {
                case TWO: os << ", TWO; " << endl;
                break;
                case THREE: os << ", THREE; " << endl;
                break;
                case FOUR: os << ", FOUR; " << endl;
                break;
                case FIVE: os << ", FIVE; " << endl;
                break;

                case SIX: os << ", SIX; " << endl;
                break;
                case SEVEN: os << ", SEVEN; " << endl;
                break;
                case EIGHT: os << ", EIGHT; " << endl;
                break;
                case NINE: os << ", NINE; " << endl;
                break;

                case TEN: os << ", TEN; " << endl;
                break;
                case JACK: os << ", JACK; " << endl;
                break;
                case QUEEN: os << ", QUEEN; " << endl;
                break;
                case KING: os << ", KING; " << endl;
                break;
                case ACE: os << ", ACE; " << endl;
                break;
             }
        }
        return os;
}

void CardDesk::putCard(Card* const &crd)
{
    Deck << crd;
}

CardDesk& operator<<(CardDesk &ds, Card* const &crd)
{
    ds.putCard(crd);
    return ds;
}
