#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "card.h"

#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QPalette>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialogButtonBox>
#include <QSlider>
#include <QString>
#include "game.h"
#include "you.h"
#include "player.h"

#include <iostream>

namespace Ui {
class MainWindow;
}

class Game;
class Player;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static MainWindow* getInstance();
    void setGame(Game* game);
    QPushButton* getfoldButton();
    QPushButton* getcallOrCheckButton();
    QPushButton* getraiseButton();
    QPushButton* getallInButton();
    QSlider* getRaiseSlider();
    QWidget* getCentralWidget();
    QLabel* getCatBetLabel(Name catName);
    QLabel* getOneYourCard(int ind);
    void changeCatBetBox(Player* player, int tBet);
    void changePot(int chips);
    void showCommunityCard(int ix);
    void showPlayerCard();
    void changeYourChipStackLabel(int cs);
    void win(Player* player);
    void activateSlider(bool isactive);
    void changeBirbImg(int whichone);

private:
    QWidget *centralWidget;
    Game* game;
    Ui::MainWindow *ui;
    static MainWindow* instance;
    QLabel* bground;

    QPushButton *foldButton;
    QPushButton *callOrCheckButton;
    QPushButton *raiseButton;
    QPushButton *allInButton;
    QSlider* youRaise;

    QLabel* playerBetLabels[5];
    QLabel* youChipsNumber;
    QLabel* tablePot;

    QLabel* Birby;

    QLabel* yourFirstCard;
    QLabel* yourSecondCard;

    QLabel* communityCards[5];
    void createButtonBox();
    void createCatBetBox();
    void createCommunityCardsBox();
    void createGeneralInfoBox();
    void createTwoYourCards();
};

#endif // MAINWINDOW_H
