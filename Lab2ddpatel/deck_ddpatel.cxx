/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
using namespace std;
#include "card_ddpatel.h"
#include "deck_ddpatel.h"

// Deck class implementation
namespace lab2_ddpatel{

    //initialize deck with 52 cards 
	Deck::Deck() : nCards(Deck::CARDS_PER_DECK), next(0), guard(10), cards{ 
    {Card(0, 1)}, {Card(0, 2)}, {Card(0, 3)}, {Card(0, 4)}, {Card(0, 5)}, {Card(0, 6)}, {Card(0, 7)}, {Card(0, 8)}, {Card(0, 9)}, {Card(0, 10)}, {Card(0, 11)}, {Card(0, 12)}, {Card(0, 13)},
    {Card(1, 1)}, {Card(1, 2)}, {Card(1, 3)}, {Card(1, 4)}, {Card(1, 5)}, {Card(1, 6)}, {Card(1, 7)}, {Card(1, 8)}, {Card(1, 9)}, {Card(1, 10)}, {Card(1, 11)}, {Card(1, 12)}, {Card(1, 13)},
    {Card(2, 1)}, {Card(2, 2)}, {Card(2, 3)}, {Card(2, 4)}, {Card(2, 5)}, {Card(2, 6)}, {Card(2, 7)}, {Card(2, 8)}, {Card(2, 9)}, {Card(2, 10)}, {Card(2, 11)}, {Card(2, 12)}, {Card(2, 13)},
    {Card(3, 1)}, {Card(3, 2)}, {Card(3, 3)}, {Card(3, 4)}, {Card(3, 5)}, {Card(3, 6)}, {Card(3, 7)}, {Card(3, 8)}, {Card(3, 9)}, {Card(3, 10)}, {Card(3, 11)}, {Card(3, 12)}, {Card(3, 13)}
} {}
	bool Deck::isEmpty() const {
        return next >= Deck::CARDS_PER_DECK;
    }
	const Card& Deck::deal() {
        // Check if the deck is empty
        shuffle();
        if (isEmpty()) {
            throw std::out_of_range("Deck is empty.");
        }

        // If the deck has less than "guard" cards left, reshuffle
        if (CARDS_PER_DECK - next <= guard) {
            shuffle();
        }

        // Deal one card from the deck
        const Card& dealtCard = cards[next++];
        
        return dealtCard;
    }

	std::ostream& operator<<(std::ostream& os, const Deck& deck) {
        for (int i = deck.next; i < Deck::CARDS_PER_DECK; ++i) {
            os << deck.cards[i] << "\n";
        }
        return os;
    }
}

