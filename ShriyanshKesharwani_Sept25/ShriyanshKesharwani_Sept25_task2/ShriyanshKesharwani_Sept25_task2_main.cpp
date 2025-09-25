// main.cpp
// Driver program to test DeckOfCards and Card classes

#include <iostream>
#include "ShriyanshKesharwani_Sept25_task2_DeckOfCards.cpp"

int main() {
    DeckOfCards deck;

    deck.shuffle(); // shuffle the deck

    std::cout << "Shuffled deck:\n\n";

    // Deal all 52 cards
    while (deck.moreCards()) 
    {
        Card card = deck.dealCard();
        std::cout << card.toString() << std::endl;
    }

    return 0;
}
