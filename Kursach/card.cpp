#include "card.h"

Card::Card()
{
    m_suit = SNONE;
    m_rank = RNONE;
}

Card::Card(Suit tsuit, Rank trank)
{
    m_suit = tsuit;
    m_rank = trank;
}

void Card::setSuit(Suit tsuit)
{
    m_suit = tsuit;
}

Suit Card::getSuit()
{
    return m_suit;
}

void Card::setRank(Rank trank)
{
    m_rank = trank;
}

Rank Card::getRank()
{
    return m_rank;
}

