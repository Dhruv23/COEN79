/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
#include <iomanip>
#include <iostream>
#include "card_ddpatel.h"
#include "deck_ddpatel.h"

using namespace std;
using namespace lab2_ddpatel;

// Test program for Deck class
int main(void) {
	Deck a;
	Deck b;
	b.shuffle();
	cout <<"unshuffled deck: \n"<<  a << "shuffled deck: \n"<< b;

	int i;
	for(i=0; i<100; i++){
		cout << i<<"th dealt card: " << a.deal() << "\n";
	}
	//cout << "dealt card: " << a.deal();
	return EXIT_SUCCESS;
}

