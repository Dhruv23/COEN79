/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;
#include "card_ddpatel.h"
#include "deck_ddpatel.h"

namespace lab2_ddpatel{
	// Fisher-Yates shuffle
	void Deck::shuffle(void) {

        //
        //setup a random generator and seed it (use a constant if you want the same shuffle repeated)
        //
		std::random_device rd;
        std::mt19937 gen(rd());
       
        

        //
        // Perform Fisher-Yates shuffle (Steps 2-4)
        //
        for (int i = CARDS_PER_DECK - 1; i > 0; --i) {
            //
            // Step 2: Pick a random number k between one and the number of unstruck numbers remaining (inclusive).
            //

            std::uniform_int_distribution<int> distribution(0, i);
            int j = distribution(gen);  // Step 3: Counting from the low end, strike out the kth number not yet struck out.

            // Swap cards[i] and cards[j] (Step 3: Write it down at the end of a separate list.)
            Card temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }

        // Reset the next index
        next = 0;
    }
}

