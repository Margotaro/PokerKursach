#include "ai.h"

AI::AI()
{

}

float AI::BrutForce(QList<Card*> myDeck, QList<Card*> mainDeck)
{
    int confidence = 0;
    float consiousnsess = 0; //TODO: translate!!

    QList<Card*> summa = myDeck+mainDeck;
    Combination* combination = DetectCombination::Detect(summa);
    QList<Card*> tCombination;
    for (int s1 = SNONE + 1; s1 <= CLUBS; s1++)
    {
        for (int r1 = RNONE + 1; r1 <= ACE; r1++)
        {
            bool unique1 = true;
            Card* tCard1 = new Card(s1, r1);
            for(int n = 0; n < summa.length(); n++)
            {
                if(tCard1 == summa[n])
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
                        Card* tCard2 = new Card(s2, r2);

                        for(int n = 0; n < summa.length(); n++)
                        {
                            if((tCard2 == summa[n])||(tCard2 == tCard1))
                            {
                                unique2 = false;
                                break;
                            }
                        }
                        if(!unique2)
                            continue;

                        QList<Card*> potentialDeck << tCard1 << tCard2 << mainDeck;
                        if(combination->compareTo(DetectCombination::Detect(potentialDeck)) > 0)
                            confidence++;
                        consiousnsess += 1;
                    }

                }

            }
        }
    }
    return confidence / consiousnsess;
    return 0.0f;
}
