// DeckOfCards class

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>
#include "ShriyanshKesharwani_Sept25_task2_Card.h"

class DeckOfCards {
    std::vector<Card> deck;   // vector of Cards
    int currentCard;          // index of next card to deal
public:
    // Constructor to initialize deck
    DeckOfCards();

    // Shuffle the deck
    void shuffle();

    // Deal one card
    Card dealCard();

    // Check if there are more cards
    bool moreCards() const;

};

#endif
