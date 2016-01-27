#ifndef _DECK_H
#define _DECK_H

#include <list>
#include <vector>
#include "Card.h"

class Deck
{
public:
    void add(Card card);   
    Card remove();
    Card back();
    Card front();
    int size();
    
    void add2(Card card);
private:
    std::list<Card> _cards;
    std::vector<Card> _cards2;
};

#endif
