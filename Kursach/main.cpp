#include <QCoreApplication>
#include <iostream>
#include "card.h"
#include "detectcombination.h"
#include <QList>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList <Card* > flashroyale, straightflush, fourofakind, fullhouse, flush, straight, set, twopairs, pair, ace;

    flashroyale << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::DIAMONDS, Rank::ACE)
                << new Card(Suit::DIAMONDS, Rank::TEN) << new Card(Suit::DIAMONDS, Rank::JACK) << new Card(Suit::DIAMONDS, Rank::KING);
    straightflush << new Card(Suit::DIAMONDS, Rank::TWO) << new Card(Suit::DIAMONDS, Rank::THREE)
                  << new Card(Suit::DIAMONDS, Rank::SIX) << new Card(Suit::DIAMONDS, Rank::FIVE)
                  << new Card(Suit::DIAMONDS, Rank::FOUR);
    fourofakind << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::DIAMONDS , Rank::QUEEN)
                << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::DIAMONDS, Rank::KING);
    fullhouse << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::CLUBS, Rank::QUEEN)
              << new Card(Suit::SPADES, Rank::QUEEN) << new Card(Suit::DIAMONDS, Rank::KING) << new Card(Suit::CLUBS, Rank::KING);
    flush << new Card(Suit::DIAMONDS, Rank::THREE) << new Card(Suit::DIAMONDS, Rank::THREE)
          << new Card(Suit::DIAMONDS, Rank::TWO) << new Card(Suit::DIAMONDS, Rank::KING) << new Card(Suit::DIAMONDS, Rank::QUEEN);
    straight << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::CLUBS, Rank::EIGHT)
             << new Card(Suit::HEARTS, Rank::JACK) << new Card(Suit::DIAMONDS, Rank::TEN) << new Card(Suit::DIAMONDS, Rank::NINE);
    set << new Card(Suit::DIAMONDS, Rank::ACE) << new Card(Suit::DIAMONDS, Rank::QUEEN)
        << new Card(Suit::HEARTS, Rank::TWO) << new Card(Suit::CLUBS, Rank::TWO) << new Card(Suit::DIAMONDS, Rank::TWO);
    twopairs << new Card(Suit::CLUBS, Rank::QUEEN) << new Card(Suit::DIAMONDS, Rank::QUEEN)
             << new Card(Suit::DIAMONDS, Rank::KING) << new Card(Suit::CLUBS, Rank::KING) << new Card(Suit::DIAMONDS, Rank::TWO);
    pair << new Card(Suit::HEARTS, Rank::SIX) << new Card(Suit::DIAMONDS, Rank::FOUR)
         << new Card(Suit::DIAMONDS, Rank::TWO) << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::CLUBS, Rank::QUEEN);
    ace << new Card(Suit::DIAMONDS, Rank::TWO) << new Card(Suit::CLUBS, Rank::FOUR)
        << new Card(Suit::HEARTS, Rank::SIX) << new Card(Suit::DIAMONDS, Rank::EIGHT) << new Card(Suit::CLUBS, Rank::NINE);


    Combination* cc = new FlashRoyale();
    Combination* cc1 = new StraightFlush(Rank::KING);
    cout << endl << "-------" << endl << cc1->compareTo(cc) << endl << "--------" << endl;

    QList <Card* > flashroyale2, straightflush2, fourofakind2, fullhouse2, flush2, straight2, set2, twopairs2, pair2, ace2;
    flashroyale2 << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::DIAMONDS, Rank::ACE)
                 << new Card(Suit::DIAMONDS, Rank::TEN) << new Card(Suit::DIAMONDS, Rank::JACK) << new Card(Suit::DIAMONDS, Rank::KING);
    straightflush2 << new  Card(Suit::DIAMONDS, Rank::TWO) << new Card(Suit::DIAMONDS, Rank::THREE)
                   << new Card(Suit::DIAMONDS, Rank::SIX) << new Card(Suit::DIAMONDS, Rank::FIVE) << new Card(Suit::DIAMONDS, Rank::FOUR);
    fourofakind2 << new Card(Suit::DIAMONDS, Rank::KING) << new Card(Suit::DIAMONDS, Rank::ACE)
                 << new Card(Suit::DIAMONDS, Rank::ACE) << new Card(Suit::DIAMONDS, Rank::ACE) << new Card(Suit::DIAMONDS, Rank::ACE);
    fullhouse2 << new Card(Suit::DIAMONDS, Rank::KING) << new Card(Suit::CLUBS, Rank::KING)
               << new Card(Suit::SPADES, Rank::KING) << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::CLUBS, Rank::QUEEN);
    flush2 << new Card(Suit::DIAMONDS, Rank::ACE) << new Card(Suit::DIAMONDS, Rank::THREE)
           << new Card(Suit::DIAMONDS, Rank::TWO) << new Card(Suit::DIAMONDS, Rank::KING) << new Card(Suit::DIAMONDS, Rank::QUEEN);
    straight2 << new Card(Suit::DIAMONDS, Rank::QUEEN) << new Card(Suit::CLUBS, Rank::KING)
              << new Card(Suit::HEARTS, Rank::JACK) << new Card(Suit::DIAMONDS, Rank::TEN) << new Card(Suit::DIAMONDS, Rank::NINE);
    set2 << new Card(Suit::DIAMONDS, Rank::ACE) << new Card(Suit::DIAMONDS, Rank::QUEEN)
         << new Card(Suit::HEARTS, Rank::KING) << new Card(Suit::CLUBS, Rank::KING) << new Card(Suit::DIAMONDS, Rank::KING);
    twopairs2 << new Card(Suit::CLUBS, Rank::QUEEN) << new Card(Suit::DIAMONDS, Rank::QUEEN)
              << new Card(Suit::DIAMONDS, Rank::ACE) <<new  Card(Suit::CLUBS, Rank::ACE) << new Card(Suit::DIAMONDS, Rank::TWO);
    pair2 << new Card(Suit::HEARTS, Rank::SIX) << new Card(Suit::DIAMONDS, Rank::FOUR) << new Card(Suit::DIAMONDS, Rank::TWO) <<new  Card(Suit::DIAMONDS, Rank::KING) << new Card(Suit::CLUBS, Rank::KING);
    ace2 << new Card(Suit::DIAMONDS, Rank::TWO) <<new Card(Suit::CLUBS, Rank::FOUR)
         << new Card(Suit::HEARTS, Rank::SIX) <<new  Card(Suit::DIAMONDS, Rank::EIGHT) << new Card(Suit::CLUBS, Rank::ACE);

    cout << (DetectCombination::Detect(flashroyale2))->compareTo(DetectCombination::Detect(fourofakind)) << endl;
    cout << (DetectCombination::Detect(straightflush))->compareTo(DetectCombination::Detect(straightflush2)) << endl;
    cout << (DetectCombination::Detect(fourofakind2))->compareTo(DetectCombination::Detect(fourofakind)) << endl;
    cout << (DetectCombination::Detect(fullhouse))->compareTo(DetectCombination::Detect(fullhouse2)) << endl;
    cout << (DetectCombination::Detect(flush2))->compareTo(DetectCombination::Detect(flush)) << endl;
    cout << (DetectCombination::Detect(straight))->compareTo(DetectCombination::Detect(straight2)) << endl;
    cout << (DetectCombination::Detect(set2))->compareTo(DetectCombination::Detect(set)) << endl;
    cout << (DetectCombination::Detect(twopairs))->compareTo(DetectCombination::Detect(twopairs2)) << endl;
    cout << (DetectCombination::Detect(pair2))->compareTo(DetectCombination::Detect(pair)) << endl;
    cout << (DetectCombination::Detect(ace))->compareTo(DetectCombination::Detect(ace2)) << endl;

    return a.exec();
}
