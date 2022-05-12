#include "Deck.h"
#include "Card.h"
#include <climits>
#include <random>
#include <vector>
#include <stdexcept>
#include <algorithm>

namespace DeckLibrary {

    //Constructor for the deck that allows the users to create a deck and choose the number of jokers.
    Deck::Deck(int numberOfJokers) {
        if (numberOfJokers < INT_MAX){ //make sure we do not overflow.
            numJokers = numberOfJokers;
        }else{
            throw std::invalid_argument("Too many jokers!");
        }

        //Add all 52 default cards here.
        for(int i=0;i<4;i++){
            for(int j=1;j<14;j++){
                deck.push_back(*new Card(i,j));
            }
        }
    }

    //This method will get one card for us.
    Card Deck::getOneCard() {
        Card card = deck.back();
        deck.pop_back();
        return card;
    }

    //This method will get the deck size.
    unsigned long long Deck::getDeckSize() const {
        return deck.size();
    }

    //This method will get the number of cards currently out.
    unsigned long long Deck::getNumOfCardsOut() const { //Const means that this method cannot modify the objects.
        return cardsOut.size();
    }

    //This method will shuffle the deck.
    void Deck::shuffleDeck() {
        using namespace std;
        shuffle(deck.begin(),deck.end(),random_device());
    }

    //This method will reset the deck for us by adding all the cards back from the cardsOut to Deck.
    void Deck::resetDeck() {
        while(!cardsOut.empty()){
            Card card = cardsOut.back();
            cardsOut.pop_back();
            deck.push_back(card);
        }
    }

    //This method will return the number of jokers in the deck.
    int Deck::getNumJokers() const {
        return numJokers;
    }


}

