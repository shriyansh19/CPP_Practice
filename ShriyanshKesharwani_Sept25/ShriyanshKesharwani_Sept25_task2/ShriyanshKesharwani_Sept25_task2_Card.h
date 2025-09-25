// Card class

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    int face;   // face value (0–12)
    int suit;   // suit value (0–3)

    // Static arrays for string representation
    static const std::string faces[13];
    static const std::string suits[4];
public:
    // Constructor to initialize face and suit
    Card(int cardFace = 0, int cardSuit = 0);

    // Return string representation of Card (e.g., "Ace of Spades")
    std::string toString() const;
};

#endif
