//
// Created by Zver on 20.11.2017.
//

#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "playingcards.h"

TEST(JerkOfCardsConstructor, DefaultConstructor)//+
{
    playingcards::JerkOfCards a1;
    ASSERT_EQ(0, a1.get_quantityofcards());
}

TEST(JerkOfCardsConstructor, InitConstructors)//+
{
    playingcards::JerkOfCards a1(2,3);
    ASSERT_EQ(1, a1.get_quantityofcards());
}

TEST(JerkOfCardsConstructor, Setters)//+
{
    playingcards::JerkOfCards a(3);
    a.set_quantityofcards(3);
    ASSERT_EQ(3, a.get_quantityofcards());
    playingcards::JerkOfCards a1(2);
    a1.set_quantityofcards(2);
    ASSERT_EQ(2, a1.get_quantityofcards());
}

TEST(JerkOfCardsConstructor, Parameters)
{
    playingcards::JerkOfCards a1;
    ASSERT_EQ(1, a1.addCardToGroup());
    ASSERT_EQ(-1, a1.suitCard(3));
    ASSERT_EQ(-1, a1.rangCard(3));
    ASSERT_EQ(1, a1.subgroupCard(2));
    playingcards::JerkOfCards a2(14);
    a2.sortCard();
    for(int i = 1;i < 14; i++){
        ASSERT_EQ(true,((a2.suitCard(i) == a2.suitCard(i + 1))&&(a2.rangCard(i) > a2.rangCard(i + 1))) || (a2.suitCard(i) < a2.suitCard(i + 1)));
    }
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

