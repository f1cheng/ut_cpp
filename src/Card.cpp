#include "Card.h"

Card::Card(int value, std::string name)
{
    _value = value;
    _name = name;
}

int Card::getValue()
{
    return _value;
}

std::string Card::getName()
{
    return _name;
}

int Card::compare(Card card)
{
    if (_value == card.getValue())
    {
        return 0;
    }
    else if (_value < card.getValue())
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

