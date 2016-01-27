#ifndef _CARD_H
#define _CARD_H

#include <string>

class Card
{
private:
    int _value;
    std::string _name;

public:
    Card(int , std::string);
    int getValue();
    std::string getName();
    int compare(Card card);
};

#endif
