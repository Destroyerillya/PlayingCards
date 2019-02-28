#include <iostream>
#include "playingcards.h"

using namespace std;
using namespace playingcards;
using std::cin;

int __main() {
    int variant;
    int suitCard = 0;
    int rangCard = 0;
    int number = 0;
    int quantityOfCards = 0;
    JerkOfCards PackOfCards;
    cout << "Enter the menu number:" << endl;
    cout << "1.Empty constructor." << endl;
    cout << "2.Constructor with quantity of cards" << endl;
    cout << "3.Constructor with one card" << endl;
    while (!getNum(variant) || variant > 4) {
        cout << "Incorrect input variant. Try again:";
    }
    switch (variant) {
        case 1: {
            break;
        }
        case 2: {
            /*cout << "Enter quantity of cards:" << endl;
            while (!getNum(quantityOfCards) || quantityOfCards > 52) {
                cout << "Incorrect input variant. Try again:";
            }
            JerkOfCards PackOfCards1(quantityOfCards);
            PackOfCards.Copy(PackOfCards1);
            //PackOfCards.input(std::cin);
            PackOfCards.print(std::cout);*/
            cin >> PackOfCards;
            cout << PackOfCards;
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
            PackOfCards.Copy(PackOfCards1);
            cout << PackOfCards;
            //PackOfCards.print(std::cout);
            break;
        }
        default:break;
    }
    do {
        cout << "Enter the menu number:" << endl;
        cout << "1.Add to group card." << endl;
        cout << "2.Search suit card." << endl;
        cout << "3.Search rang card." << endl;
        cout << "4.Sort." << endl;
        cout << "5.Subgroup." << endl;
        cout << "6.Output." << endl;
        cout << "7.Create copy constructor and output it." << endl;
        cout << "8.Recreate constructor" << endl;
        cout << "9.EXIT!" << endl;
        cin.clear();
        while (!getNum(variant) || variant>9) {
            cout << "Incorrect input variant. Try again:";
        }
        switch (variant) {
            case 1: {
                //PackOfCards.addCardToGroup();
                //PackOfCards.print(std::cout);
                PackOfCards += PackOfCards;
                cout << PackOfCards;
                break;
            }
            case 2: {
                cout << "Enter number of your card:" << endl;
                while (!getNum(number)) {
                    cout << "Incorrect input variant. Try again:";
                }
                if(PackOfCards.suitCard(number) == -1) {
                    cout << "Sry but this card not exist in pack!" << endl;
                }
                else{
                    cout << "Suit of your card:" << endl;
                    cout << PackOfCards.suitCard(number) << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter number of your card:" << endl;
                while (!getNum(number)) {
                    cout << "Incorrect input variant. Try again:";
                }
                if(PackOfCards.rangCard(number) == -1){
                    cout << "Sry but this card not exist in pack!" << endl;
                }
                else{
                    cout << "Rang of your card:" << endl;
                    cout << PackOfCards.rangCard(number) << endl;
                }
                break;
            }
            case 4: {
                PackOfCards.sortCard();
                cout << PackOfCards;
                //PackOfCards.print(std::cout);
                break;
            }
            case 5: {
                cout << "Enter suit of your subpack:" << endl;
                while (!getNum(suitCard) || suitCard > 4) {
                    cout << "Incorrect input variant. Try again:";
                }
                PackOfCards.subgroupCard(suitCard);
                break;
            }
            case 6: {
                cout << PackOfCards;
                //PackOfCards.print(std::cout);
                break;
            }
            case 7: {
                JerkOfCards PackOfCards1 (PackOfCards);
                cout << "Your new constructor copy" << endl;
                cout << PackOfCards1;
                JerkOfCards PackOfCards (PackOfCards1);
                cout << "Your original constructor" << endl;
                cout << PackOfCards;
                break;
            }
            case 8: {
                PackOfCards =PackOfCards;
                break;
            }
            case 9: {
                return 0;
            }
            default:break;
        }
    }while (variant != 9);
    return 0;
}