#include "player.h"

int Player::minimumBet = 0;
int Player::BigBlind = 20;

Player::Player(int cs)
{
    ChipStack = cs;
    outOfGame = false;
    outOfRound = false;
    Bet = 0;
}

int Player::getMinimumBet() {
    return minimumBet;
}

int Player::Raise(int chips)
{
    chips += minimumBet;
    if(ChipStack - chips > 0)
    {
        ChipStack -= chips;
        minimumBet = chips;
        return chips;
    }
    else
    {
        return AllIn();
    }
}

int Player::Check()
{
   return 0;
}

int Player::Call()
{
    ChipStack -= minimumBet - Bet;
    return minimumBet;
}

int Player::Fold()
{
    outOfRound = true;
    return -1;
}

int Player::AllIn()
{
    int tChipStack;
    tChipStack = ChipStack;
    ChipStack = 0;
    if(tChipStack > minimumBet)
        minimumBet = tChipStack + Bet;
    return tChipStack + Bet;
}

void Player::switchRound()
{
    desk.clear();
    outOfRound = false;
}

void Player::takeaPot(int cs)
{
    ChipStack += cs;
}

bool Player::isOutOfGame()
{
    return outOfGame;
}

bool Player::isOutOfRound()
{
    return outOfRound;
}

int Player::getChipStack()
{
    return ChipStack;
}

int Player::makeaBigBlind()
{
    ChipStack -= BigBlind;
    minimumBet = BigBlind;
    Bet = BigBlind;
    return Bet;
}

int Player::makeaSmallBlind()
{
    ChipStack -= BigBlind/2;
    BigBlind *= 2;
    Bet = BigBlind/4;
    return Bet;
}

QList<Card* > Player::getTwoCards()
{
    return desk.getDeck();
}

void Player::setname(string tname)
{
    name = tname;
}

string Player::showname()
{
    return name;
}
