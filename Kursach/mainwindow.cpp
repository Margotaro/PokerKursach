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
    centralWidget->setStyleSheet("font-family: 'Bad Script';");

    this->setFixedSize(QSize(1280, 780));
    instance = this;

    QPixmap pix("C:\\Users\\Margotaro\\Desktop\\REPOSITORY\\PokerKursach\\PekorCards\\fon.jpg");
    pix = pix.scaled(1280, 780);
    bground = new QLabel(centralWidget);
    bground->setGeometry(0, 0, 1280, 780);
    bground->setPixmap(pix);
    bground->show();

    Birby = new QLabel(centralWidget);
    Birby->setGeometry(1150, 50, 80, 80);
    Birby->setStyleSheet("background-image: url(C:/Users/Margotaro/Desktop/REPOSITORY/Birby.png);");

    createButtonBox();
    createCatBetBox();
    createCommunityCardsBox();
    createGeneralInfoBox();
    createTwoYourCards();
}

void MainWindow::createButtonBox()
{
    setStyleSheet("QPushButton {"
                  "border-style: outset;"
                  "border-width: 0px;"
                  "}");

    foldButton = new QPushButton(tr("&Fold"), centralWidget);
    foldButton->setGeometry(20, 630, 75, 50);
    foldButton->setEnabled(false);
    foldButton->setStyleSheet("background-image: url(C:/Users/Margotaro/Desktop/REPOSITORY/PokerKursach/TemporaryFiles/FoldButton.png);"
                              "border: none;"
                              "background-color: transparent;"
                              "color: white;"
                              "font-size: 12pt;"
                              "background-repeat: no-repeat;");

    callOrCheckButton = new QPushButton(tr("&Check"), centralWidget);
    callOrCheckButton->setGeometry(100, 630, 72, 51);
    callOrCheckButton->setEnabled(false);
    callOrCheckButton->setStyleSheet("background-image: url(C:/Users/Margotaro/Desktop/REPOSITORY/PokerKursach/TemporaryFiles/CallCheckButton.png);"
                                    "border: none;"
                                    "background-color: transparent;"
                                    "color: white;"
                                    "font-size: 12pt;"
                                    "background-repeat: no-repeat;");

    raiseButton = new QPushButton(tr("&Raise"), centralWidget);
    raiseButton->setGeometry(185, 630, 76, 48);
    raiseButton->setEnabled(false);
    raiseButton->setStyleSheet("background-image: url(C:/Users/Margotaro/Desktop/REPOSITORY/PokerKursach/TemporaryFiles/RaiseButton.png);"
                               "border: none;"
                               "background-color: transparent;"
                               "color: white;"
                               "font-size: 12pt;"
                               "background-repeat: no-repeat;");

    allInButton = new QPushButton(tr("&All in"), centralWidget);
    allInButton->setGeometry(275, 630, 83, 53);
    allInButton->setEnabled(false);
    allInButton->setStyleSheet("background-image: url(C:/Users/Margotaro/Desktop/REPOSITORY/PokerKursach/TemporaryFiles/AllInButton.png);"
                               "border: none;"
                               "background-color: transparent;"
                               "color: white;"
                               "font-size: 12pt;"
                               "background-repeat: no-repeat;");

    youRaise = new QSlider(centralWidget);
    youRaise->setOrientation(Qt::Horizontal);
    youRaise->setGeometry(20, 690, 311, 80);
    setStyleSheet("QSlider::groove:horizontal {"
                  "background-image:  url(C:/Users/Margotaro/Desktop/REPOSITORY/PokerKursach/Slider/SliderLine.png);"
                  "height: 33 px;"
                  "width: 311 px;"
                  "background-repeat: no-repeat;"
                  "}"
                  "QSlider::handle:horizontal {"
                  "background-image:  url(C:/Users/Margotaro/Desktop/REPOSITORY/PokerKursach/Slider/SliderButton.png);"
                  "height: 60 px;"
                  "width: 60 px;"
                  "margin: -23 0px;"
                  "background-repeat: no-repeat;"
                  "}"
                  );
    activateSlider(false);
}

void MainWindow::activateSlider(bool isactive)
{
    youRaise->setMinimum(0);
    youRaise->setMaximum(You::getInstance()->getChipStack() - Player::getMinimumBet());
    youRaise->setPageStep(You::getInstance()->getChipStack() / 5);
    youRaise->setEnabled(isactive);
}

void MainWindow::changeBirbImg(int whichone)
{
    if (whichone == -1)
    {
        Birby->resize(108, 80);
        Birby->setStyleSheet("background-image: url(C:/Users/Margotaro/Desktop/REPOSITORY/lostBirb.png);");
    }
    else if (whichone == 0)
    {
        Birby->resize(80, 80);
        Birby->setStyleSheet("background-image: url(C:/Users/Margotaro/Desktop/REPOSITORY/Birby.png);");
    }

    else if (whichone == 1)
    {
        Birby->resize(112, 89);
        Birby->setStyleSheet("background-image: url(C:/Users/Margotaro/Desktop/REPOSITORY/winnerBirb.png);");
    }
}

void MainWindow::createCatBetBox()
{
    playerBetLabels[Name::FirstCat] = new QLabel(centralWidget);
    playerBetLabels[Name::FirstCat]->setText("First Cat bet");
    playerBetLabels[Name::FirstCat]->move(250, 240);

    playerBetLabels[Name::SecondCat] = new QLabel(centralWidget);
    playerBetLabels[Name::SecondCat]->setText("Second Cat bet");
    playerBetLabels[Name::SecondCat]->move(480, 210);

    playerBetLabels[Name::ThirdCat] = new QLabel(centralWidget);
    playerBetLabels[Name::ThirdCat]->setText("Third Cat bet");
    playerBetLabels[Name::ThirdCat]->move(780, 210);

    playerBetLabels[Name::FourthCat] = new QLabel(centralWidget);
    playerBetLabels[Name::FourthCat]->setText("Fourth Cat bet");
    playerBetLabels[Name::FourthCat]->move(1040, 240);

    playerBetLabels[Name::YourCat] = new QLabel("Your bet", centralWidget);
    playerBetLabels[Name::YourCat]->setGeometry(1060, 25, 100, 75);
    playerBetLabels[Name::YourCat]->setStyleSheet("color: #851111; font-size: 28pt;");

    for(int i = FirstCat; i < YourCat; i++)
        playerBetLabels[i]->setStyleSheet("color: #315a55; font-size: 24pt;");
}

void MainWindow::createCommunityCardsBox()
{
    for(int i = 0; i < 5; i++)
    {
        communityCards[i] = new QLabel(centralWidget);
        communityCards[i]->setGeometry(372 + 108*i, 46, 75, 110);
    }
}

void MainWindow::createGeneralInfoBox()
{
    youChipsNumber = new QLabel("Number of chips", centralWidget);
    youChipsNumber->setGeometry(1180, -20, 100, 75);
    youChipsNumber->setStyleSheet("color: #851111; font-size: 28pt;");
    tablePot = new QLabel("0", centralWidget);
    tablePot->setGeometry(1000, 80, 100, 75);
    tablePot->setStyleSheet("color: #851111; font-size: 28pt;");
}

void MainWindow::createTwoYourCards()
{
    yourFirstCard = new QLabel(centralWidget);
    yourFirstCard->setGeometry(530, 500, 100, 160);

    yourSecondCard = new QLabel(centralWidget);
    yourSecondCard->setGeometry(615, 520, 100, 160);

}

void MainWindow::changeCatBetBox(Player* player, int tBet)
{
    if(tBet == -1)
        playerBetLabels[player->getLabelName()]->setText("folded");
    else
        playerBetLabels[player->getLabelName()]->setText(QString::number(tBet));
    if(player->getLabelName() == Name::YourCat)
        changeYourChipStackLabel(player->getChipStack());
    this->repaint();
}

void MainWindow::changePot(int chips)
{
    tablePot->setText(QString::number(chips));
}

void MainWindow::showCommunityCard(int ix)
{
    communityCards[ix]->setStyleSheet("QLabel { opacity: 0.5 }");
    communityCards[ix]->setPixmap(*(game->getTable()->getCommunityCards()[ix]->getCardFace()));
    communityCards[ix]->setScaledContents(true);
}

void MainWindow::changeYourChipStackLabel(int cs)
{
    youChipsNumber->setText(QString::number(cs));
}

void MainWindow::win(Player* player)
{
    playerBetLabels[player->getLabelName()]->setText("winner");
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


QSlider* MainWindow::getRaiseSlider()
{
    return youRaise;
}

QWidget* MainWindow::getCentralWidget()
{
    return centralWidget;
}

QLabel* MainWindow::getCatBetLabel(Name catName)
{
    return playerBetLabels[catName];
}

QLabel* MainWindow::getOneYourCard(int ind)
{
    if(ind == 1)
        return yourFirstCard;
    else if(ind == 2)
        return yourSecondCard;
    return nullptr;
}
