#include "detectcombination.h"

DetectCombination::DetectCombination()
{

}

Combination* DetectCombination::Detect(QList<Card *> cards)
{
    Combination* current = NULL;
    current = DetectFlashRoyale(cards);
    if(current != NULL)
        return current;
    // current = DetectStraightFlush(cards);
    // if(current != NULL)
    //     return current;
}

FlashRoyale* DetectFlashRoyale(QList<Card *> cards)
{
    qSort(cards.begin(), cards.end(), compareSuits);
    QList<Card *> hearts;
    QList<Card *> clubs;
    QList<Card *> diamonds;
    QList<Card *> spades;

    bool c[5] = { false };
    for(int i = 0; i < cards.length() - 5; i++)
    {
        if(cards[i]->getSuit() == Suit::HEARTS)
            hearts.append(cards[i]);
        if(cards[i]->getSuit() == Suit::CLUBS)
            clubs.append(cards[i]);
        if(cards[i]->getSuit() == Suit::DIAMONDS)
            diamonds.append(cards[i]);
        if(cards[i]->getSuit() == Suit::SPADES)
            spades.append(cards[i]);
    }
    if(hearts.length() >= 5)
        for(int i = 0; i < hearts.length(); i++)
            if(hearts[i]->getRank() - Rank::TEN >= 0)
                c[hearts[i]->getRank() - Rank::TEN] = true;
    bool isAll = true;
    for(int i = 0; i < 5; i++)
        if(!c[i]) isAll = false;
    if(isAll)
        return new FlashRoyale();

    for(int i = 0; i < 5; i++)
        c[i] = false;
    if(clubs.length() >= 5)
        for(int i = 0; i < clubs.length(); i++)
            if(clubs[i]->getRank() - Rank::TEN >= 0)
                c[clubs[i]->getRank() - Rank::TEN] = true;
    bool isAll = true;
    for(int i = 0; i < 5; i++)
        if(!c[i]) isAll = false;
    if(isAll)
        return new FlashRoyale();

    for(int i = 0; i < 5; i++)
        c[i] = false;
    if(diamonds.length() >= 5)
        for(int i = 0; i < diamonds.length(); i++)
            if(diamonds[i]->getRank() - Rank::TEN >= 0)
                c[diamonds[i]->getRank() - Rank::TEN] = true;
    bool isAll = true;
    for(int i = 0; i < 5; i++)
        if(!c[i]) isAll = false;
    if(isAll)
        return new FlashRoyale();

    for(int i = 0; i < 5; i++)
        c[i] = false;
    if(spades.length() >= 5)
        for(int i = 0; i < spades.length(); i++)
            if(spades[i]->getRank() - Rank::TEN >= 0)
                c[spades[i]->getRank() - Rank::TEN] = true;
    bool isAll = true;
    for(int i = 0; i < 5; i++)
        if(!c[i]) isAll = false;
    if(isAll)
        return new FlashRoyale();
    return NULL;
}

bool compareSuits(Card* c1, Card* c2)
{
    return c1->getSuit() > c2->getSuit();
}

//static bool DetectCombination::returnTrue()
//{
//    return true;
//}
