#ifndef _DECK_H
#define _DECK_H

#include <list>
#include "Card.h"

class Deck
{
public:
    void add(Card card);   
    Card remove();
    Card back();
    Card front();
    int size();

private:
    std::list<Card> _cards;
};

#endif
