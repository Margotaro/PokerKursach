#include "ai.h"

AI::AI(int cs) : Player(cs)
{
    srand(time(NULL));
    personality = rand() % 50 + 50; //Характер -- уверенность в выигрыше между 50% и 100%
}

void AI::TakeaCard(Card* card)
{
    desk << card;
    QLabel* label = new QLabel(MainWindow::getInstance());
    label->setGeometry((desk.length() + 1) * 110, 0 , 100, 160);
    label->setPixmap(*(card->getCardFace()));
}

int AI::Parlay(Table* t)
{
    float persentage = GetConfidence(desk.getDeck(), t->getCommunityCards());
    float decision;
    if(ChipStack - Player::getMinimumBet() > 0) {
        cout << endl << ChipStack << ' ' << Player::getMinimumBet() << endl;
        float x = Player::getMinimumBet() / ChipStack;
        decision = (x * std::pow(2 * std::asin(persentage) / 3.1415926535, 3) + persentage * (1 - x));
    }
    else if(persentage > 0.9)
    {
        return AllIn();
    }
    else {
        return Fold();
    }
    cout << "decision: " << decision << endl;
    if(decision <= 0.15) {
       cout << "Fold" << endl;
       return Fold();
    }
    else if(decision <= 0.6) {
       cout << "Call" << endl;
       return Call();
    }
    else {
       cout << "Raise" << endl;
       if(Player::getMinimumBet() < decision * 300)
            return Raise(decision * 100);
       return Call();
    }
}

float AI::GetConfidence(QList<Card*> &myDeck, QList<Card*> &mainDeck)
{
    float confidence = 0;
    float consсiousness = 0;

    QList<Card*> summa = myDeck+mainDeck;

    Combination* combination = DetectCombination::Detect(summa);

    for (int s1 = SNONE + 1; s1 <= CLUBS; s1++)
    {
        for (int r1 = RNONE + 1; r1 <= ACE; r1++)
        {
            bool unique1 = true;
            Card* tCard1 = new Card((Suit)s1, (Rank)r1);
            for(int n = 0; n < summa.length(); n++)
            {
                if((*tCard1) == (*summa[n]))
                {
                    unique1 = false;
                    break;
                }
            }
            if(!unique1)
                continue;
            {
                for (int s2 = SNONE + 1; s2 <= CLUBS; s2++)
                {
                    for (int r2 = RNONE + 1; r2 <= ACE; r2++)
                    {
                        bool unique2 = true;
                        Card* tCard2 = new Card((Suit)s2, (Rank)r2);

                        for(int n = 0; n < summa.length(); n++)
                        {
                            if(((*tCard2) == (*summa[n]))||((*tCard2) == (*tCard1)))
                            {
                                unique2 = false;
                                break;
                            }
                        }
                        if(!unique2)
                            continue;

                        QList<Card*> potentialDeck;
                        potentialDeck << tCard1 << tCard2 << mainDeck;
                        if(combination->compareTo(DetectCombination::Detect(potentialDeck)) > 0)
                            confidence += 2.0;
                        else if(combination->compareTo(DetectCombination::Detect(potentialDeck)) == 0)
                            confidence += 1.0;
                        consсiousness += 2.0;
                    }

                }

            }
        }
    }
    return confidence/consсiousness;
}
