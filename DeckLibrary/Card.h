#ifndef DECK_LIBRARY_CARD_H
#define DECK_LIBRARY_CARD_H

#include "string"
namespace DeckLibrary{
    class Card {
    private:
        //Key for Suits.
        //0 = Spades, 1 = Hearts, 2 = Diamonds, 3 = Clubs, 4 = Joker.
        //Key for Rank.
        //All cards are their normal value, 1 = A, 11 = J, 12 = Q, 13 = K.
        int suit;
        int rank;
    public:
        Card(int suit,int rank);
        [[nodiscard]]int getCardSuit() const;
        [[nodiscard]]int getCardRank() const;
        [[nodiscard]] std::string toString() const;
    };
}



#endif //DECK_LIBRARY_CARD_H
