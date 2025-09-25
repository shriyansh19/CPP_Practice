// Member-function definitions for Card class

#include "ShriyanshKesharwani_Sept25_task2_Card.h"

// Initialize static arrays
const std::string Card::faces[13] = {
    "Ace", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

const std::string Card::suits[4] = {
    "Hearts", "Diamonds", "Clubs", "Spades"
};

// Constructor
Card::Card(int cardFace, int cardSuit) {
    face = cardFace;
    suit = cardSuit;
}

// Return card as string
std::string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}
