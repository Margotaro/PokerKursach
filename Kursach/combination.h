#ifndef COMBINATION_H
#define COMBINATION_H


class Combination
{
public:
    Combination();
    int getValue();
    virtual bool compareTo(Combination* c) = 0;
private:
    int value;
};

#endif // COMBINATION_H
