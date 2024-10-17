/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
#ifndef POKER_H
#define POKER_H
#include <array>
// Poker class
namespace lab2_ddpatel{
	class Poker {
	public:
		// An int to define each of the poker ranking
		// in decending order here.  Therefore 0 is the lowest rank, which is High card
		using PokerRank_t = int;
		// You could also use enum
		static const PokerRank_t POKER_STRAIGHT_FLUSH = 8; //done, works
		static const PokerRank_t POKER_QUAD = 7; //done, works
		static const PokerRank_t POKER_FULLHOUSE = 6; //done, works
		static const PokerRank_t POKER_FLUSH = 5; //done, works
		static const PokerRank_t POKER_STRAIGHT = 4; //done, works
		static const PokerRank_t POKER_TRIPLE = 3; //done, works
		static const PokerRank_t POKER_2_PAIR = 2; //done, works
		static const PokerRank_t POKER_PAIR = 1; //done, works
		static const PokerRank_t POKER_HIGHCARD = 0; //done, works

		Poker();
		void dealHand();
		int rankHand(std::array<Card, 5> input);
		void assignHand(std::array<Card, 5> input);
		std::array<Card, 5> getHand();
		friend std::ostream& operator<<(std::ostream& os, const Poker &c);

	private:
		Deck deck;
		// use a member to store the the hand as opposed to dealHand returning a pointer
		std::array<Card, 5> hand;
		// don't want to deal with new/delete yet

		// helper functions for ranking, you should implement them in poker.cxx
		bool isFlush(uint s[]) {return false; }
		bool isStraight(uint r[]) {return false; }
		bool isQuad(uint r[]) {return false; }
		bool isTriple(uint r[]) {return false; }
		bool is2Pair(uint r[]) {return false; }
		bool isPair(uint r[]) {return false; }
	};
}

#endif // POKER_H
