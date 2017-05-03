#include "player.h"

int Player::minimumBet = 0;

Player::Player(int cs)
{
    ChipStack = cs;
    outOfGame = false;
    outOfRound = false;
}

int Player::Raise(int chips)
{
    ChipStack -= chips;
    if(chips > minimumBet)
        minimumBet = chips;
    return chips;
}

int Player::Check()
{
   return 0;
}

int Player::Call()
{
    ChipStack -= minimumBet;
    return minimumBet;
}

int Player::Fold()
{
    outOfRound = true;
    return 0;
}

int Player::AllIn()
{
    int tChipStack;
    tChipStack = ChipStack;
    ChipStack = 0;
    return tChipStack;
}

void Player::switchRound()
{
    desk.clear();
    return;
}

void Player::takeaPot(int cs)
{
    ChipStack += cs;
}

int Player::makeaBet(int b)
{
    ChipStack -= b;
    return b;
}

bool Player::isOutOfGame()
{
    return outOfGame;
}

bool Player::isOutOfRound()
{
    return outOfRound;
}
