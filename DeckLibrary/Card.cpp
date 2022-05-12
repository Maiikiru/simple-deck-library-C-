#include "Card.h"
#include <stdexcept>

namespace DeckLibrary{
    //The constructor here will ensure that each card actually has a suit and rank.
    Card::Card(int suit, int rank) {
        if(suit > 4 || suit < 0) throw std::invalid_argument("Invalid suit.");
        if(rank > 4 || rank < 0) throw std::invalid_argument("Invalid rank");
        this->suit = suit;
        this-> rank = rank;
    }

    //This method will get the card rank of the card.
    int Card::getCardRank() const {
        return rank;
    }

    //This method will get the card suit of the card.
    int Card::getCardSuit() const {
        return suit;
    }

    //This method will return a string representation of the card.
    std::string Card::toString() const {
        using namespace std;
        string string{};
        switch(rank){
            case 14:
                return "Joker";
            case 13:
                string+"K";
                break;
            case 12:
                string+"Q";
                break;
            case 11:
                string+"J";
                break;
            default:
                string+to_string(rank);
        }

        switch(suit){
            case 0:
                string+"of Spades";
                break;
            case 1:
                string+"of Hearts";
                break;
            case 2:
                string+"of Diamonds";
                break;
            case 3:
                string+"of Clubs";
                break;
            case 4:
                return "Joker";
            default:
                throw invalid_argument("Invalid card suit.");
        }

        return string;

    }


}
