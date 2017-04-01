#include "detectcombination.h"

using namespace std;

DetectCombination::DetectCombination() : maybeCombination { false }, nRanks { 0 }
{

}

Card* DetectCombination::getHighestCard(QList<Card*> cards)
{
    Card* theHighest = cards[0];
    for(int i = 0; i < cards.length(); i++)
        if(theHighest->getRank() < cards[i]->getRank()) theHighest = cards[i];
    return theHighest;
}

Combination* DetectCombination::Detect(QList<Card *> cards)
{
    DetectCombination detector;
    Combination* current = nullptr;
    current = detector.DetectFlashRoyale(cards);
    if(current != nullptr)
        return current;
    current = detector.DetectStraightFlush(cards);
    if(current != nullptr)
        return current;
    current = detector.DetectFourOfaKind(cards);
    if(current != nullptr)
        return current;
    current = detector.DetectFullHouse(cards);
    if(current != nullptr)
        return current;
    current = detector.DetectFlush(cards);
    if(current != nullptr)
        return current;
    current = detector.DetectStraight(cards);
    if(current != nullptr)
        return current;
    current = detector.DetectSet(cards);
    if(current != nullptr)
        return current;
    current = detector.DetectTwoPair(cards);
    if(current != nullptr)
        return current;
    current = detector.DetectOnePair(cards);
    if(current != nullptr)
        return current;
    return new HighCard((detector.getHighestCard(cards))->getRank());
}

FlashRoyale* DetectCombination::DetectFlashRoyale(QList<Card *> cards)
{
    for(int  i = 0; i< 5; i++)
        maybeCombination[i] = false;
    qSort(cards.begin(), cards.end(),
          [](Card* c1, Card* c2) -> bool { return c1->getSuit() > c2->getSuit(); });
    QList<Card *> hearts;
    QList<Card *> clubs;
    QList<Card *> diamonds;
    QList<Card *> spades;

    for(int i = 0; i < cards.length(); i++)
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
                maybeCombination[hearts[i]->getRank() - Rank::TEN] = true;
    bool isAll = true;
    for(int i = 0; i < 5; i++)
        if(!maybeCombination[i]) isAll = false;
    if(isAll)
        return new FlashRoyale();


    for(int i = 0; i < 5; i++)
        maybeCombination[i] = false;
    if(clubs.length() >= 5)
        for(int i = 0; i < clubs.length(); i++)
            if(clubs[i]->getRank() - Rank::TEN >= 0)
                maybeCombination[clubs[i]->getRank() - Rank::TEN] = true;
    isAll = true;
    for(int i = 0; i < 5; i++)
        if(!maybeCombination[i]) isAll = false;
    if(isAll)
        return new FlashRoyale();

    for(int i = 0; i < 5; i++)
        maybeCombination[i] = false;
    if(diamonds.length() >= 5)
        for(int i = 0; i < diamonds.length(); i++)
            if(diamonds[i]->getRank() - Rank::TEN >= 0)
                maybeCombination[diamonds[i]->getRank() - Rank::TEN] = true;
    isAll = true;
    for(int i = 0; i < 5; i++)
        if(!maybeCombination[i]) isAll = false;
    if(isAll)
        return new FlashRoyale();

    for(int i = 0; i < 5; i++)
        maybeCombination[i] = false;
    if(spades.length() >= 5)
        for(int i = 0; i < spades.length(); i++)
            if(spades[i]->getRank() - Rank::TEN >= 0)
                maybeCombination[spades[i]->getRank() - Rank::TEN] = true;
    isAll = true;
    for(int i = 0; i < 5; i++)
        if(!maybeCombination[i]) isAll = false;
    if(isAll)
        return new FlashRoyale();
    return nullptr;
}

Flush* DetectCombination::DetectFlush(QList<Card *> cards)
{
    n_hearts.clear();
    n_spades.clear();
    n_clubs.clear();
    n_diamonds.clear();

    for (int i = 0; i < cards.length(); i++)
    {
        if(cards[i]->getSuit() == Suit::HEARTS) n_hearts.append(cards[i]);
        else if(cards[i]->getSuit() == Suit::SPADES) n_spades.append(cards[i]);
        else if(cards[i]->getSuit() == Suit::CLUBS) n_clubs.append(cards[i]);
        else n_diamonds.append(cards[i]);
    }

    if (n_hearts.length() >= 5)
        return new Flush(n_hearts);
    else if (n_spades.length() >= 5)
        return new Flush(n_spades);
    else if (n_clubs.length() >= 5)
        return new Flush(n_clubs);
    else if (n_diamonds.length() >= 5)
        return new Flush(n_diamonds);
    return nullptr;
}

FourOfaKind* DetectCombination::DetectFourOfaKind(QList<Card *> cards)
{
    for(int  i = 0; i < 14; i++)
        nRanks[i] = 0;
    for (int i = 0; i < cards.length(); i++)
    {
        ++nRanks[cards[i]->getRank()];
        if(nRanks[cards[i]->getRank()] >= 4)
            return new FourOfaKind(cards[i]->getRank());
    }
    return nullptr;
}

FullHouse* DetectCombination::DetectFullHouse(QList<Card *> cards)
{
    for(int  i = 0; i < 14; i++)
        nRanks[i] = 0;

    for (int i = 0; i < cards.length(); i++)
        ++nRanks[cards[i]->getRank()];

    bool fullhouse[2];
    fullhouse[0] = false;
    fullhouse[1] = false;
    int rankOfSet, rankOfPair;

    for (int i = 0; i < 14; i++)
    {
        if(nRanks[i] >= 3)
        {
            fullhouse[0] = true;
            rankOfSet = i;
            break;
        }
    }

    for (int i = 0; i < 14; i++)
    {

        if((nRanks[i] >= 2)&&(i != rankOfSet))
        {
            fullhouse[1] = true;
            rankOfPair = i;
        }
    }

    if(fullhouse[0]&&fullhouse[1])
        return new FullHouse((Rank)rankOfSet, (Rank)rankOfPair);
    return nullptr;
}

StraightFlush* DetectCombination::DetectStraightFlush(QList<Card*> cards)
{
    for (int i = 0; i < cards.length(); i++)
    {
        if(cards[i]->getSuit() == Suit::HEARTS) n_hearts.append(cards[i]);
        else if(cards[i]->getSuit() == Suit::SPADES) n_spades.append(cards[i]);
        else if(cards[i]->getSuit() == Suit::CLUBS) n_clubs.append(cards[i]);
        else n_diamonds.append(cards[i]);
    }
    
    Rank theHighestIndex = Rank::RNONE;
    
    if(n_hearts.length() >= 5)
    {
        qSort(n_hearts.begin(), n_hearts.end(), [](Card* c1, Card* c2) -> bool { return c1->getRank() > c2->getRank(); });
        int counter = 0;
        for(int i = 1; i < n_hearts.length(); i++)
        {
            if(n_hearts[i-1]->getRank() - n_hearts[i]->getRank() > 1) counter = 0;
            else if(n_hearts[i-1]->getRank() - n_hearts[i]->getRank() == 1) counter++;
            if(counter == 4) theHighestIndex = n_hearts[i - 4]->getRank();
        }
    }

    else if(n_clubs.length() >= 5)
    {
        qSort(n_clubs.begin(), n_clubs.end(), [](Card* c1, Card* c2) -> bool { return c1->getRank() > c2->getRank(); });
        int counter = 0;
        for(int i = 1; i < n_clubs.length(); i++)
        {
            if(n_clubs[i-1]->getRank() - n_clubs[i]->getRank() > 1) counter = 0;
            else if(n_clubs[i-1]->getRank() - n_clubs[i]->getRank() == 1) counter++;
            if(counter == 4) theHighestIndex = n_clubs[i - 4]->getRank();
        }
    }
            
    else if(n_diamonds.length() >= 5)
    {
        qSort(n_diamonds.begin(), n_diamonds.end(), [](Card* c1, Card* c2) -> bool { return c1->getRank() > c2->getRank(); });
        int counter = 0;
        for(int i = 1; i < n_diamonds.length(); i++)
        {
            if(n_diamonds[i-1]->getRank() - n_diamonds[i]->getRank() > 1) counter = 0;
            else if(n_diamonds[i-1]->getRank() - n_diamonds[i]->getRank() == 1) counter++;
            if(counter == 4) theHighestIndex = n_diamonds[i - 4]->getRank();
        }
    }

    else if(n_spades.length() >= 5)
    {
        qSort(n_spades.begin(), n_spades.end(), [](Card* c1, Card* c2) -> bool { return c1->getRank() > c2->getRank(); });
        int counter = 0;
        for(int i = 1; i < n_spades.length(); i++)
        {
            if(n_spades[i-1]->getRank() - n_spades[i]->getRank() > 1) counter = 0;
            else if(n_spades[i-1]->getRank() - n_spades[i]->getRank() == 1) counter++;
            if(counter == 4) theHighestIndex = n_spades[i - 4]->getRank();
        }
    }
    if (theHighestIndex)
        return new StraightFlush(theHighestIndex);
    return nullptr;
}

Straight* DetectCombination::DetectStraight(QList<Card*> cards)
{
    Rank theHighestIndex = Rank::RNONE;

    qSort(cards.begin(), cards.end(), [](Card* c1, Card* c2) -> bool { return c1->getRank() > c2->getRank(); });

    int counter = 0;
    for(int i = 1; i < cards.length(); i++)
    {
        if(cards[i-1]->getRank() - cards[i]->getRank() > 1) counter = 0;
        else if(cards[i-1]->getRank() - cards[i]->getRank() == 1) counter++;
        if(counter == 4) theHighestIndex = cards[i - 4]->getRank();
    }
    if(theHighestIndex != 0)
        return new Straight(theHighestIndex);
    return nullptr;
}

Set* DetectCombination::DetectSet(QList<Card*> cards)
{
    for(int  i = 0; i < 14; i++)
        nRanks[i] = 0;
    for (int i = 0; i < cards.length(); i++)
    {
        ++nRanks[cards[i]->getRank()];
    }
    int rankOfSet = 0;

    for (int i = 0; i < 14; i++)
    {
        if(nRanks[i] == 3)
        {
            rankOfSet = i;
            break;
        }
    }
    if(rankOfSet)
        return new Set((Rank)rankOfSet);
    return nullptr;
}

TwoPair* DetectCombination::DetectTwoPair(QList<Card*> cards)
{
    for(int  i = 0; i < 14; i++)
        nRanks[i] = 0;
    for (int i = 0; i < cards.length(); i++)
    {
        ++nRanks[cards[i]->getRank()];
    }

    bool twopair[2];
    int rankOfPair1, rankOfPair2;

    for (int i = 0; i < 14; i++)
    {
        if(nRanks[i] == 2)
        {
            twopair[0] = true;
            rankOfPair1 = i;
            break;
        }
    }

    for (int i = 0; i < 14; i++)
    {

        if((nRanks[i] == 2)&&(i != rankOfPair1))
        {
            twopair[1] = true;
            rankOfPair2 = i;
            break;
        }
    }

    if(twopair[0] && twopair[1])
        return new TwoPair((Rank)rankOfPair1, (Rank)rankOfPair2);
    return nullptr;
}

OnePair* DetectCombination::DetectOnePair(QList<Card*> cards)
{
    for(int  i = 0; i < 14; i++)
        nRanks[i] = 0;
    for (int i = 0; i < cards.length(); i++)
    {
        ++nRanks[cards[i]->getRank()];
    }
    int rankOfPair = 0;

    for (int i = 0; i < 14; i++)
    {
        if(nRanks[i] == 2)
        {
            rankOfPair = i;
            break;
        }
    }

    if(rankOfPair)
        return new OnePair((Rank)rankOfPair);
    return nullptr;
}
