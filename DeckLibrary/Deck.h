#ifndef DECK_LIBRARY_DECK_H
#define DECK_LIBRARY_DECK_H

#include "vector"
#include "Card.h"

namespace DeckLibrary{
    class Deck{
    private:
        std::vector<Card> deck;
        std::vector<Card> cardsOut;
        unsigned long long numCardsOut = 0;
        int numJokers = 0;
    public:
        explicit Deck(int numJokers);
        Card getOneCard();
        void shuffleDeck();
        [[nodiscard]] unsigned long long getDeckSize() const;
        [[nodiscard]] unsigned long long getNumOfCardsOut() const; //nodiscard means that if you call this method and do nothing with the results, it will give a warning.
        [[nodiscard]] int getNumJokers() const;
        void resetDeck();
    };
}

#endif //DECK_LIBRARY_DECK_H
