//
// Created by Zver on 14.10.2017.
//
#include "playingcards.h"
using namespace std;

namespace playingcards {

    JerkOfCards::JerkOfCards(int quantityofcards1) {
        int t = 0;
        quantityofcards = quantityofcards1;
        Card* pack = new Card[quantityofcards];
        for(int count = 0;count != quantityofcards;count++){
            int randsuit = rand() % Spades + Hearts;
            int randrang = rand() % King + C2;
            if(count != 0) {
                while(t != count) {
                    while ((pack[t].suitCard == randsuit) && (pack[t].rangCard == randrang)) {
                        randsuit = rand() % Spades + Hearts;
                        randrang = rand() % King + C2;
                        t = 0;
                    }
                    t++;
                }
            }
            pack[count].suitCard = randsuit;
            pack[count].rangCard = randrang;
            t = 0;
        }
        this->pack = pack;
    }

    JerkOfCards::JerkOfCards(int suitcard,int rangcard){
        int count = 0;
        quantityofcards = 1;
        Card* pack = new Card[quantityofcards];
        pack[count].suitCard = suitcard;
        pack[count].rangCard = rangcard;
        this->pack = pack;
    }

    JerkOfCards::JerkOfCards(const JerkOfCards &Original) {
        quantityofcards = Original.quantityofcards;
        pack = new Card [quantityofcards];
        for(int i = 0; i < quantityofcards ; i++) {
            pack[i].suitCard = Original.pack[i].suitCard;
            pack[i].rangCard = Original.pack[i].rangCard;
        }
    }

    JerkOfCards::JerkOfCards(JerkOfCards &&Original):quantityofcards(Original.quantityofcards),pack(Original.pack){
        Original.pack = nullptr;
    }

    JerkOfCards& JerkOfCards::set_quantityofcards(int quantityofcards1) {
        try {
            if(quantityofcards1 < 0)
                throw std::exception();
        } catch (std::exception e) {
            cout << "EXCEPTION CAUGHT";
        }
        quantityofcards = quantityofcards1;
        return *this;
    }

    int JerkOfCards::addCardToGroup(){
        int count = 0;
        int t = 0;
        int randsuit = 0;
        int randrang = 0;
        Card *pack2 = new Card[quantityofcards + 1];
        if (quantityofcards > 51) {
            cout << "Very much cards in group, my ENGLISH IS PERFECT!SRY!" << endl;
        } else {
            if (quantityofcards != 0) {
                for (count = 0; count != quantityofcards; count++) {
                    randsuit = rand() % Spades + Hearts;
                    randrang = rand() % King + C2;
                    if (quantityofcards != 0) {
                        while (t != count) {
                            while ((pack[t].suitCard == randsuit) && (pack[t].rangCard == randrang)) {
                                randsuit = rand() % Spades + Hearts;
                                randrang = rand() % King + C2;
                                t = 0;
                            }
                            t++;
                        }
                    }
                    t = 0;
                }
                if (count == quantityofcards) {
                    for (int i = 0; i != quantityofcards; i++) {
                        pack2[i].suitCard = pack[i].suitCard;
                        pack2[i].rangCard = pack[i].rangCard;
                    }
                    pack2[quantityofcards].suitCard = randsuit;
                    pack2[quantityofcards].rangCard = randrang;
                    pack = new Card[quantityofcards + 1];
                    for (int j = 0; j != quantityofcards; j++) {
                        pack[j].suitCard = pack2[j].suitCard;
                        pack[j].rangCard = pack2[j].rangCard;
                    }
                    this->pack = pack;
                    this->pack[quantityofcards].suitCard = randsuit;
                    this->pack[quantityofcards].rangCard = randrang;
                    quantityofcards++;
                }
            } else {
                randsuit = rand() % Spades + Hearts;
                randrang = rand() % King + C2;
                pack[quantityofcards].suitCard = randsuit;
                pack[quantityofcards].rangCard = randrang;
                this->pack[quantityofcards].suitCard = randsuit;
                this->pack[quantityofcards].rangCard = randrang;
                quantityofcards++;
            }
            cout << "Card was add to group!" << endl;
        }
        delete pack2;
        return 1;
    }

    int JerkOfCards::suitCard(int number) const{
        if(number > quantityofcards){
            return -1;
        }
        else {
            return pack[number-1].suitCard;
        }
    }

    int JerkOfCards::rangCard(int number) const{
        if(number > quantityofcards){
            return -1;
        }
        else {
            return pack[number-1].rangCard;
        }
    }

    void JerkOfCards::sortCard(){
        if(quantityofcards == 0){
            cout << "Sry but your pack is empty" << endl;
        }
        else{
            int t = 0;
            int k = 0;
            for(int i = 0; i < quantityofcards - 1; i++){
                for (int j = 0; j < quantityofcards - 1; j++){
                    if ((pack[j].suitCard == pack[j + 1].suitCard) && (pack[j].rangCard < pack[j + 1].rangCard)){
                        t = pack[j + 1].rangCard;
                        pack[j + 1].rangCard = pack[j].rangCard;
                        pack[j].rangCard = t;
                    }
                    if (pack[j].suitCard > pack[j + 1].suitCard) {
                        t = pack[j + 1].suitCard;
                        k = pack[j + 1].rangCard;
                        pack[j + 1 ].suitCard = pack[j].suitCard;
                        pack[j + 1 ].rangCard = pack[j].rangCard;
                        pack[j].suitCard = t;
                        pack[j].rangCard = k;
                    }
                }
            }
        }
    }

    int JerkOfCards::subgroupCard(int suitcard){
        int i = 0;
        int t = 0;
        if(quantityofcards != 0) {
            for (i = 0; i != quantityofcards; i++) {
                if (pack[i].suitCard == suitcard) {
                    subpack[t].suitCard = pack[i].suitCard;
                    subpack[t].rangCard = pack[i].rangCard;
                    t++;
                }
            }
            if(subpack == nullptr){
                cout << "Sry subpack is not exist cards!" << endl;
            }
            else {
                cout << "Subgroup of our cards:" << endl;
                for (i = 0; i != t; i++) {
                    cout << subpack[i].suitCard << " " << subpack[i].rangCard << endl;
                }
            }
        }
        else{
            cout << "Your main pack is empty!" <<endl;
        }
        return 1;
    }

    int JerkOfCards::testSort(){
        int count = 0;
        for(count = 0; count < quantityofcards; count++){
            if((pack[count].suitCard == pack[count + 1].suitCard) && (pack[count].rangCard < pack[count + 1].rangCard)){
                return 0;
            }
            if((pack[count].suitCard > pack[count + 1].suitCard) && (pack[count + 1].suitCard != 0)){
                cout << pack[count].suitCard << endl;
                return 0;
            }
        }
        return 1;
    }

    void JerkOfCards::Copy(const JerkOfCards&Original){
        quantityofcards = Original.quantityofcards;
        for(int i = 0; i !=52 ; i++) {
            pack[i] = Original.pack[i];
        }
    }

    istream & operator >> (istream & in, JerkOfCards & PackOfCards ) {
        int t = 0;
        cout << "Enter quantity of cards: ";
        while (!getNum(PackOfCards.quantityofcards) || PackOfCards.quantityofcards > 52) {
            cout << "Incorrect input variant. Try again:";
        }
        for(int count = 0;count != PackOfCards.quantityofcards;count++){
            int randsuit = rand() % 4 + 1;
            int randrang = rand() % 13 + 2;
            if(count != 0) {
                while(t != count) {
                    while ((PackOfCards.pack[t].suitCard == randsuit) && (PackOfCards.pack[t].rangCard == randrang)) {
                        randsuit = rand() % 4 + 1;
                        randrang = rand() % 13 + 2;
                        t = 0;
                    }
                    t++;
                }
            }
            PackOfCards.pack[count].suitCard = randsuit;
            PackOfCards.pack[count].rangCard = randrang;
            t = 0;
        }
        return in;
    }

    ostream & operator << (ostream &cout, const JerkOfCards &PackOfCards) {
        if(PackOfCards.quantityofcards != 0) {
            for(int i = 0; i != PackOfCards.quantityofcards; i++) {
                cout << PackOfCards.pack[i].suitCard << ' ';
                cout << PackOfCards.pack[i].rangCard << ' ';
                cout << std::endl;
            }
            return cout;
        }
        else {
            cout << "Empty" <<endl;
            return cout;
        }
    }

    istream &JerkOfCards::input(istream &in) {
        int t = 0;
        cout << "Enter quantity of cards: ";
        while (!getNum(quantityofcards) || quantityofcards > 52) {
            cout << "Incorrect input variant. Try again:";
        }
        for(int count = 0;count != quantityofcards;count++){
            int randsuit = rand() % 4 + 1;
            int randrang = rand() % 13 + 2;
            if(count != 0) {
                while(t != count) {
                    while ((pack[t].suitCard == randsuit) && (pack[t].rangCard == randrang)) {
                        randsuit = rand() % 4 + 1;
                        randrang = rand() % 13 + 2;
                        t = 0;
                    }
                    t++;
                }
            }
            pack[count].suitCard = randsuit;
            pack[count].rangCard = randrang;
            t = 0;
        }
        return in;
    }

    ostream &JerkOfCards::print(ostream &cout) const{
        if(quantityofcards != 0) {
            for (int i = 0; i != quantityofcards; i++) {
                cout << pack[i].suitCard << ' ';
                cout << pack[i].rangCard << ' ';
                cout << std::endl;
            }
            return cout;
        }
        else {
            cout << "Empty" <<endl;
            return cout;
        }
    }

    JerkOfCards &JerkOfCards::operator += (const JerkOfCards &) {
        int count = 0;
        int t = 0;
        int randsuit = 0;
        int randrang = 0;
        Card *pack2 = new Card[quantityofcards + 1];
        if (quantityofcards > 51) {
            cout << "Very much cards in group, my ENGLISH IS PERFECT!SRY!" << endl;
        } else {
            if (quantityofcards != 0) {
                for (count = 0; count != quantityofcards; count++) {
                    randsuit = rand() % Spades + Hearts;
                    randrang = rand() % King + C2;
                    if (quantityofcards != 0) {
                        while (t != count) {
                            while ((pack[t].suitCard == randsuit) && (pack[t].rangCard == randrang)) {
                                randsuit = rand() % Spades + Hearts;
                                randrang = rand() % King + C2;
                                t = 0;
                            }
                            t++;
                        }
                    }
                    t = 0;
                }
                if (count == quantityofcards) {
                    for (int i = 0; i != quantityofcards; i++) {
                        pack2[i].suitCard = pack[i].suitCard;
                        pack2[i].rangCard = pack[i].rangCard;
                    }
                    pack2[quantityofcards].suitCard = randsuit;
                    pack2[quantityofcards].rangCard = randrang;
                    pack = new Card[quantityofcards + 1];
                    for (int j = 0; j != quantityofcards; j++) {
                        pack[j].suitCard = pack2[j].suitCard;
                        pack[j].rangCard = pack2[j].rangCard;
                    }
                    this->pack = pack;
                    this->pack[quantityofcards].suitCard = randsuit;
                    this->pack[quantityofcards].rangCard = randrang;
                    quantityofcards++;
                }
            } else {
                randsuit = rand() % Spades + Hearts;
                randrang = rand() % King + C2;
                pack[quantityofcards].suitCard = randsuit;
                pack[quantityofcards].rangCard = randrang;
                this->pack[quantityofcards].suitCard = randsuit;
                this->pack[quantityofcards].rangCard = randrang;
                quantityofcards++;
            }
            cout << "Card was add to group!" << endl;
        }
        delete pack2;
    }

    JerkOfCards &JerkOfCards::operator = (JerkOfCards &Original) {
        int variant;
        int suitCard = 0;
        int rangCard = 0;
        int number = 0;
        int quantityOfCards = 0;
        cout << "Enter the menu number:" << endl;
        cout << "1.Empty constructor." << endl;
        cout << "2.Constructor with quantity of cards" << endl;
        cout << "3.Constructor with one card" << endl;
        while (!getNum(variant) || variant > 4) {
            cout << "Incorrect input variant. Try again:";
        }
        switch (variant) {
            case 1: {
                Original.quantityofcards = 0;
                Original.pack = new Card [Original.quantityofcards];
                break;
            }
            case 2: {
                cin >> Original;
                cout << Original;
                break;
            }
            case 3: {
                cout << "Enter suit of card:" << endl;
                while (!getNum(suitCard) || suitCard > 4 || suitCard < 1) {
                    cout << "Incorrect input variant. Try again:";
                }
                cout << "Enter rang of card:" << endl;
                while (!getNum(rangCard) || rangCard > 14 || rangCard < 2) {
                    cout << "Incorrect input variant. Try again:";
                }
                JerkOfCards PackOfCards1 (suitCard, rangCard);
                Original.Copy(PackOfCards1);
                cout << Original;
                break;
            }
            default:break;
        }
    }

    JerkOfCards &JerkOfCards::operator = (JerkOfCards &&Original){
        int i = 0;
        int tmp = quantityofcards;
        quantityofcards = Original.quantityofcards;
        Original.quantityofcards = tmp;
        Card *ptr = pack;
        pack = Original.pack;
        Original.pack = ptr;
        return *this;
    }
}