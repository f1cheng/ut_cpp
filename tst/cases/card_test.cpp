#include "Card.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(card_test, init)
{

  Card card(1, "AAA");
  EXPECT_EQ(1, card.getValue());
  EXPECT_EQ("AAA", card.getName());

}

TEST(card_test, compare_equal)
{

  Card card(1, "AAA");
  Card card2(1, "AAA");
  EXPECT_EQ(0, card.compare(card2));

}

TEST(card_test, compare_less_than)
{

  Card card(1, "AAA");
  Card card2(2, "BBB");
  EXPECT_EQ(-1, card.compare(card2));

}

TEST(card_test, compare_bigger_than)
{

  Card card(3, "CCC");
  Card card2(2, "BBB");
  EXPECT_EQ(1, card.compare(card2));

}
