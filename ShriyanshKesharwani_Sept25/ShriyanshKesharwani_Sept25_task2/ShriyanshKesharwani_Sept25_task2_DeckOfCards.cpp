// Member-function definitions for DeckOfCards class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ShriyanshKesharwani_Sept25_task2_DeckOfCards.h"

// Constructor: initialize deck with 52 cards
DeckOfCards::DeckOfCards() {
    for (int suit = 0; suit < 4; suit++) 
    {
        for (int face = 0; face < 13; face++) 
        {
            deck.push_back(Card(face, suit));
        }
    }
    currentCard = 0;
}

// Shuffle the deck using simple swap algorithm
void DeckOfCards::shuffle() {

    std::srand(static_cast<unsigned int>(std::time(0))); // seed random

    for (int i = 0; i < deck.size(); i++) 
    {
        int j = std::rand() % deck.size();
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    currentCard = 0; // reset dealing position
}

// Deal one card
Card DeckOfCards::dealCard() {
    if (moreCards()) 
    {
        return deck[currentCard++];
    } 
    else 
    {
        return Card(); // return default card if no cards left
    }
}

// Check if more cards are left
bool DeckOfCards::moreCards() const {
    return currentCard < (deck.size());
}
