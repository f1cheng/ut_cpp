#include "Deck.h"

void Deck::add(Card card)
{
    _cards.push_back(card);
}

Card Deck::remove()
{
    Card card = _cards.back();
    _cards.pop_back();
    return card;
}

Card Deck::back()
{
    return _cards.back();
}

Card Deck::front()
{
    return _cards.front();
}

int Deck::size()
{
    return _cards.size();
}
