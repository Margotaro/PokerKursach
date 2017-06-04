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

namespace Ui {
class MainWindow;
}

class Game;

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
    QWidget* getCentralWidget();

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

    QLabel* firstCatBet;
    QLabel* secondCatBet;
    QLabel* thirdCatBet;
    QLabel* fourthCatBet;
    QLabel* yourBet;

    QLabel* nameLabel;
    QLabel* youChipsNumber;
    QLabel* youBet;
    QLabel* tablePot;

    QLabel* communityCards[5];
    void createButtonBox();
    void createCatBetBox();
    void createCommunityCardsBox();
    void createGeneralInfoBox();
};

#endif // MAINWINDOW_H
