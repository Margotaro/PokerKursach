#include "you.h"
#include <iostream>

You* You::instance = 0;
int You::howManyCardsDoYouHaveRightNow = 0;

You::You(int cs) : Player(cs)
{
    instance = this;
    firstBetDone = false;
    playerID = Name::YourCat;
    Place = 0;
}

void You::TakeaCard(Card* card)
{
    desk << card;
    howManyCardsDoYouHaveRightNow++;
    MainWindow::getInstance()->getOneYourCard(howManyCardsDoYouHaveRightNow)->setPixmap(*(card->getCardFace()));
    MainWindow::getInstance()->getOneYourCard(howManyCardsDoYouHaveRightNow)->setScaledContents(true);
}

void You::dropCards()
{
    howManyCardsDoYouHaveRightNow = 0;
}

int You::Parlay(Table *t)
{
    setActiveForButtons(true);

    loop = new QEventLoop;

    if(!firstBetDone)
    {
        if(!(t->callCheck()))
        {
            MainWindow::getInstance()->getcallOrCheckButton()->setText("Call");
            QObject::connect(MainWindow::getInstance()->getcallOrCheckButton(), SIGNAL(clicked()), this, SLOT(YouCall()));
        }
        else
        {
            MainWindow::getInstance()->getcallOrCheckButton()->setText("Check");
            QObject::connect(MainWindow::getInstance()->getcallOrCheckButton(), SIGNAL(clicked()), this, SLOT(YouCheck()));
        }
        QObject::connect(MainWindow::getInstance()->getfoldButton(), SIGNAL(clicked(bool)), this, SLOT(YouFold()));
        QObject::connect(MainWindow::getInstance()->getallInButton(), SIGNAL(clicked(bool)), this, SLOT(YouAllIn()));
        QObject::connect(MainWindow::getInstance()->getraiseButton(), SIGNAL(clicked(bool)), this, SLOT(YouRaise()));
        QObject::connect(MainWindow::getInstance()->getRaiseSlider(), SIGNAL(valueChanged(int)),this,SLOT(sliderValueChanged(int)));
        firstBetDone = true;
    }
    int betIs = loop->exec();
    cout << "betIs: " + betIs << endl;
    return betIs;
}

void You::sliderValueChanged(int value)
{
    sliderVariable = value;
    MainWindow::getInstance()->getCatBetLabel(Name::YourCat)->setText(QString::number(value + Bet));
    MainWindow::getInstance()->getraiseButton()->setEnabled(true);
}

void You::setActiveForButtons(bool isActive)
{
    MainWindow::getInstance()->getallInButton()->setEnabled(isActive);
    MainWindow::getInstance()->getcallOrCheckButton()->setEnabled(isActive);
    MainWindow::getInstance()->getfoldButton()->setEnabled(isActive);
    MainWindow::getInstance()->activateSlider(isActive);
    MainWindow::getInstance()->getraiseButton()->setEnabled(false);
}

You* You::getInstance()
{
    return instance;
}

void You::YouRaise()
{
    std::cout << "You've raised";
    yourDecision = Raise(sliderVariable);
    setActiveForButtons(false);
    loop->exit(yourDecision);
}

void You::YouCheck()
{
    std::cout << "You've checked";
    yourDecision = Check();
    setActiveForButtons(false);
    loop->exit(yourDecision);
}

void You::YouCall()
{
    if(minimumBet <= ChipStack)
    {
        std::cout << "You've called";
        yourDecision = Call();
        setActiveForButtons(false);
        loop->exit(yourDecision);
    }
}

void You::YouFold()
{
    std::cout << "You've folded";
    yourDecision = Fold();
    setActiveForButtons(false);
    loop->exit(yourDecision);
}

void You::YouAllIn()
{
    std::cout << "You've allined";
    yourDecision = AllIn();
    setActiveForButtons(false);
    loop->exit(yourDecision);
}
