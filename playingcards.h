//
// Created by Zver on 30.10.2017.
//

#ifndef LABASOLO3ENUM_PLAYINGCARDS_H
#define LABASOLO3ENUM_PLAYINGCARDS_H

#include <iostream>
#include <cstring>
#include <limits>
#include <random>
#include <cmath>

using namespace std;

namespace playingcards{

    struct Card {
        int suitCard;
        int rangCard;
    };

    class JerkOfCards{
    public:
        JerkOfCards() {quantityofcards = 0; pack = new Card[quantityofcards];};//-empty constructor
        JerkOfCards(int quantityofcards1);//-constructor of quantity cards
        JerkOfCards(int suitCard, int rangCard);//-constructor with one card
        JerkOfCards(const JerkOfCards &);
        JerkOfCards(JerkOfCards &&);
        ~JerkOfCards() {delete [] pack; delete [] subpack;};

        void Copy(const JerkOfCards &);//-copypast constructors

        int addCardToGroup();//-addcard to group peregruzka

        int suitCard(int number) const;//-search suit of card+

        int rangCard(int number) const;//-search rang of card+

        void sortCard();//-sort group

        int subgroupCard (int suitcard);//-create subgroup of card with suit

        int testSort();

        istream & input (istream &);

        ostream & print (ostream &) const;

        friend istream & operator >> (istream &, JerkOfCards & );

        friend ostream & operator << (ostream &, const JerkOfCards &);

        JerkOfCards & operator += (const JerkOfCards &);

        JerkOfCards & operator = (JerkOfCards &);

        JerkOfCards & operator = (JerkOfCards &&);

        int get_quantityofcards() const{return quantityofcards;};//+
        JerkOfCards& set_quantityofcards(int quantityofcards1);//+

    private:
        int quantityofcards;
        enum suit {Hearts = 1, Diamonds = 2, Clubs = 3, Spades = 4};
        enum rang {C2 = 2,C3 = 3, C4 = 4, C5 = 5, C6 = 6, C7 = 7, C8 = 8, C9 = 9, C10 = 10, Jack = 11, Queen = 12, King = 13, Ace = 14};
        Card *pack;
        Card *subpack = new Card[12];
    };

    template <class T>

    int getNum(T &a) {
        int t;
        std::cin >> a;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (a > 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

#endif //LABASOLO3ENUM_PLAYINGCARDS_H
