/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
#include <iomanip>
#include <iostream>
#include <string>
#include "card_ddpatel.h"

using namespace std;
using namespace lab2_ddpatel;

// Test program for Card
int main(void) {
	// test code just for Card class
    Card card1(0, 13);  // 10 of Spades
//    Card card2(1, 5);   // 5 of Hearts
    Card card2(0, 10);   // 5 of Hearts

    // Compare the two cards
    if (card1 < card2) {
        std::cout << card1 << " is less than " << card2 << std::endl;
    } else {
        std::cout << card1 << " is greater than or equal to " << card2 << std::endl;
    }

	Card myCard(0, 10);
	int cardValue = myCard;
    int cardrank = myCard.getRank();
    int cardsuit = myCard.getSuit();
    // Print the integer value
    std::cout << "Integer value of the card: " << cardValue << std::endl;
    std::cout << "Integer value of the rank: " << cardrank << std::endl;
    std::cout << "Integer value of the suit: " << cardsuit << std::endl;

    return 0;
	return EXIT_SUCCESS;
}
