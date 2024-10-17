/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
#include <iomanip>
#include <iostream>
#include "card_ddpatel.h"
using namespace std;

// Stand-alone Card definitions
namespace lab2_ddpatel {
	// Card::Card(suit_t s=0, rank_t r=0): rank{r}, suit{s} {}

    std::ostream& operator<<(std::ostream& os, const Card& c) {
        const char* suits[] = {"♠", "♥", "♦", "♣"}; // Define suit glyphs, 0 = spades, 1 = hearts, 2 = diamonds, 3 = clubs
        const char* ranks[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

        os << ranks[c.rank]<< suits[c.suit];
        return os;
    }

    Card::operator int() const {
		// int
        return static_cast<int>(rank);
    }
	bool Card::operator<(const Card& other) const {
        if (rank == other.rank) {
            return suit < other.suit;
        }
        return rank < other.rank;
    }
	
	Card::Card(suit_t init_suit, rank_t init_rank){
		this->rank = init_rank;
		this->suit = init_suit;
	}
    int Card::getRank(){
        return this->rank;
    }
    int Card::getSuit(){
        return this->suit;
    }

	
}
