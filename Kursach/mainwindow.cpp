#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow* MainWindow::instance = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    this->setFixedSize(QSize(1300, 780));
    instance = this;

    QPixmap pix("C:\\Users\\Margotaro\\Desktop\\REPOSITORY\\PokerKursach\\PekorCards\\fon.jpg");
    pix = pix.scaled(1300, 780);
    bground = new QLabel(centralWidget);
    bground->setGeometry(0, 0, 1300, 780);
    bground->setPixmap(pix);
    bground->show();

    QSlider* YouRaise = new QSlider(centralWidget);
    YouRaise->setGeometry(500, 700, 730, 710);

    createButtonBox();
    createCatBetBox();
    createCommunityCardsBox();
    createGeneralInfoBox();

//    communityCards[0]->setStyleSheet("QWidget { opacity: 0.5 }");
//    communityCards[0]->setPixmap(*(game->getTable()->getCommunityCards()[0]->getCardFace()));
}

void MainWindow::createButtonBox()
{
    foldButton = new QPushButton(tr("&Fold"), centralWidget);
    foldButton->setGeometry(20, 630, 60, 40);
    foldButton->setEnabled(false);

    callOrCheckButton = new QPushButton(tr("&Check"), centralWidget);
    callOrCheckButton->setGeometry(110, 630, 60, 40);
    callOrCheckButton->setEnabled(false);

    raiseButton = new QPushButton(tr("&Raise"), centralWidget);
    raiseButton->setGeometry(210, 630, 60, 40);
    raiseButton->setEnabled(false);

    allInButton = new QPushButton(tr("&All in"), centralWidget);
    allInButton->setGeometry(310, 630, 60, 40);
    allInButton->setEnabled(false);

}

void MainWindow::createCatBetBox()
{
    firstCatBet = new QLabel(centralWidget);
    firstCatBet->setText("First Cat bet");
    firstCatBet->move(250, 240);

    secondCatBet = new QLabel(centralWidget);
    secondCatBet->setText("Second Cat bet");
    secondCatBet->move(480, 210);

    thirdCatBet = new QLabel(centralWidget);
    thirdCatBet->setText("Third Cat bet");
    thirdCatBet->move(780, 210);

    fourthCatBet = new QLabel(centralWidget);
    fourthCatBet->setText("Fourth Cat bet");
    fourthCatBet->move(1040, 210);

    youBet = new QLabel(centralWidget);
    yourBet->setText("Your bet");

}

void MainWindow::createCommunityCardsBox()
{
    for(int i = 0; i < 5; i++)
    {
        communityCards[i] = new QLabel("Text", centralWidget);
        communityCards[i]->setGeometry(440 + 130*i, 20, 100, 160);
    }
}

void MainWindow::createGeneralInfoBox()
{

    nameLabel = new QLabel("Name", centralWidget);
    nameLabel->move(1060, 40);
    youChipsNumber = new QLabel("Number of chips", centralWidget);
    youChipsNumber->move(1180, 80);
    tablePot = new QLabel("Pot", centralWidget);
    tablePot->move(1090, 110);
    yourBet = new QLabel("Your label", centralWidget);
    yourBet->move(1040, 140);
}

void MainWindow::setGame(Game* game)
{
    this->game = game;
}

MainWindow* MainWindow::getInstance()
{
    return instance;
}

MainWindow::~MainWindow()
{
    delete ui;
}


QPushButton* MainWindow::getfoldButton()
{
    return foldButton;
}

QPushButton* MainWindow::getcallOrCheckButton()
{
    return callOrCheckButton;
}

QPushButton* MainWindow::getraiseButton()
{
    return raiseButton;
}

QPushButton* MainWindow::getallInButton()
{
    return allInButton;
}

QWidget* MainWindow::getCentralWidget()
{
    return centralWidget;
}
