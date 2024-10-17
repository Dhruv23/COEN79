// card.h
#ifndef CARD_H
#define CARD_H

#include <iostream>

namespace lab2_ddpatel {
	class Card {
	public:
		using rank_t = int;
		using suit_t = int;
		Card(suit_t init_suit, rank_t init_rank);
		
	friend std::ostream& operator<<(std::ostream& os, const Card &c);
	bool operator<(const Card& other) const;
	int getSuit();
	int getRank();
	// encode a card into an integer
	operator int() const;

	private:
		rank_t rank;	// A, King, Queen, ..., 2
		suit_t suit;	// Spade, Heart, Diamond, Club
	};
}

#endif // CARD_H
