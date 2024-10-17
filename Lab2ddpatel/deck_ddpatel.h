/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
namespace lab2_ddpatel{
	// Deck class with an embedded Card class
	// See stand-alone Card class in "card.h"
	class Deck {
	public:
		static const size_t CARDS_PER_DECK = 52;
		Deck();
		// contructor here to initialize members
		const Card &deal(void);
		bool isEmpty() const;
		void shuffle(void);

	friend std::ostream& operator<<(std::ostream& os, const Deck &);

	private:
		int nCards;
		Card cards[CARDS_PER_DECK];
		int next;
		int guard;
	};
}
