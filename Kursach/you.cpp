#include "you.h"

You* You::instance = 0;

You::You(int cs) : Player(cs)
{
    instance = this;
    Place = 0;
}

void You::TakeaCard(Card* card)
{
    desk << card;
    QLabel* label = new QLabel(MainWindow::getInstance());
    label->setGeometry(0,0,100, 160);
    label->setPixmap(*(card->getCardFace()));
}

int You::Parlay(Table *t)
{
    setActiveForButtons(true);

    loop = new QEventLoop;

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

    return loop->exec();
}

void You::setActiveForButtons(bool isActive)
{
    MainWindow::getInstance()->getallInButton()->setEnabled(isActive);
    MainWindow::getInstance()->getcallOrCheckButton()->setEnabled(isActive);
    MainWindow::getInstance()->getfoldButton()->setEnabled(isActive);
    MainWindow::getInstance()->getraiseButton()->setEnabled(isActive);
}

You* You::getInstance()
{
    return instance;
}

void You::YouRaise()
{
    std::cout << "You've raised";
    int raiseChips = 20;
    yourDecision = Raise(raiseChips);
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
    std::cout << "You've called";
    yourDecision = Call();
    setActiveForButtons(false);
    loop->exit(yourDecision);
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
