#include "Deck.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(deck_test, add_cards)
{
    Card a(1, "A");
    Card b(2, "B");
    Deck deck;
    deck.add(a);
    deck.add(b);
    ASSERT_TRUE(2 == deck.size());
    ASSERT_TRUE(0 == b.compare(deck.back()));
    ASSERT_TRUE(0 == a.compare(deck.front()));
}


TEST(deck_test, remove_cards)
{
    Card a(1, "A");
    Card b(2, "B");
    Deck deck;
    deck.add(a);
    deck.add(b);
    deck.remove();
    ASSERT_TRUE(0 == a.compare(deck.remove()));
    ASSERT_TRUE(0 == deck.size());
}
