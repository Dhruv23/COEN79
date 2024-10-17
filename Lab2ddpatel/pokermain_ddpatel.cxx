/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include "card_ddpatel.h"
#include "deck_ddpatel.h"
#include "poker_ddpatel.h"
#include <array>
#include<unistd.h>


using namespace std;
using namespace lab2_ddpatel;

Poker pokerHands(Poker poker){
	std::array<Card, 5> testHand = poker.getHand(); // generate a hand and store it locally
	
	

	cout << "randomly generated hand: " << poker << endl; //print out the randomly generated hand
	
	
	cout << "One hand for each ranking" << endl;

	//suit first then rank (generating a case for high card)
	testHand = {Card(1,2), Card(2,8), Card(3,6), Card(1,3), Card(0, 1)}; 
	int rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (High Card), "<<"Hand is: " << poker <<endl;

	//suit first then rank (generating a case for Pair)
	testHand = {Card(1,2), Card(2,2), Card(3,6), Card(1,3), Card(0, 1)}; 
	rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (Pair), "<<"Hand is: " << poker <<endl;
	
	//suit first then rank (generating a case for 2 Pair)
	testHand = {Card(1,2), Card(2,2), Card(3,6), Card(1,6), Card(0, 1)}; 
	rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (Two Pair), "<<"Hand is: " << poker <<endl;

	//suit first then rank (generating a case for Triple)
	testHand = {Card(1,2), Card(2,2), Card(3,2), Card(1,3), Card(0, 1)}; 
	rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (Triple), "<<"Hand is: " << poker <<endl;

	//suit first then rank (generating a case for Straight)
	testHand = {Card(1,2), Card(2,3), Card(3,4), Card(1,5), Card(0, 6)}; 
	rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (Straight), "<<"Hand is: " << poker <<endl;

	//suit first then rank (generating a case for Flush)
	testHand = {Card(1,2), Card(1,3), Card(1,2), Card(1,3), Card(1, 1)}; 
	rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (Flush), "<<"Hand is: " << poker <<endl;

	//suit first then rank (generating a case for Full House)
	testHand = {Card(1,2), Card(2,2), Card(3,2), Card(1,3), Card(0, 3)}; 
	rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (Full House), "<<"Hand is: " << poker <<endl;

	//suit first then rank (generating a case for Quad)
	testHand = {Card(1,2), Card(2,2), Card(3,2), Card(1,2), Card(0, 3)}; 
	rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (Quad), "<<"Hand is: " << poker <<endl;

	//suit first then rank (generating a case for Flush)
	testHand = {Card(1,2), Card(1,3), Card(1,4), Card(1,5), Card(1, 6)}; 
	rank = poker.rankHand(testHand);
	poker.assignHand(testHand);
	cout <<"Rank is: "<< rank << " (Straight Flush), "<<"Hand is: " << poker <<endl;
	return poker;
}
Poker pokerStats(Poker poker){
	double count = 1;
	double highCount = 0;
	double pairCount = 0;
	double twoPairCount = 0;
	double tripleCount = 0;
	double straightCount = 0;
	double flushCount = 0;
	double fullHouseCount = 0;
	double quadCount = 0;
	double straightFlushCount = 0;
	Poker tester;
	int hold;

	std::clock_t start, end;
    double duration;

    start = std::clock();
	for(count = 0; count<72192; count++){ //odds for one straightflush are 1/72192
		tester.dealHand();
		std::array<Card, 5> testerRanker = tester.getHand();
		hold = tester.rankHand(testerRanker);
		if(hold == 0){
			highCount++;
		}else if(hold ==1){
			pairCount++;
		}else if(hold ==2){
			twoPairCount++;
		}else if(hold ==3){
			tripleCount++;
		}else if(hold ==4){
			straightCount++;
		}else if(hold==5){
			flushCount++;
		}else if(hold ==6){
			fullHouseCount++;
		}else if(hold ==7){
			quadCount++;
		}else if(hold ==8){
			straightFlushCount++;
		}else{
			continue;
		}
	}
	cout << "Statistics:" << endl;
	cout << "Number of Generated Hands: " << count<< endl;
	cout << "Percentage of High Card Hands: "<< highCount/count * 100<< "%"<< endl;
	cout << "Percentage of Pair Hands: "<< pairCount/count * 100 << "%"<< endl;
	cout << "Percentage of Two Pair Hands: "<< twoPairCount/count * 100 << "%"<< endl;
	cout << "Percentage of Triple Hands: "<< tripleCount/count * 100 << "%"<< endl;
	cout << "Percentage of Straight Hands: "<< straightCount/count * 100 << "%"<< endl;
	cout << "Percentage of Flush Hands: "<< flushCount/count * 100 << "%"<< endl;
	cout << "Percentage of Full House Hands: "<< fullHouseCount/count * 100 << "%"<< endl;
	cout << "Percentage of Quad Hands: "<< quadCount/count * 100 << "%"<< endl;
	cout << "Percentage of Straight Flush Hands: "<< straightFlushCount/count * 100 << "%"<< endl;
	cout << "Number of Straight Flush Hands (percentage can be too small): " << straightFlushCount <<endl;
	end = std::clock();
	duration = (double) (end-start) / CLOCKS_PER_SEC;
	cout << duration << " seconds total" <<endl;
	cout << duration/count << " seconds per hand" <<endl;
	return poker;
}
// Poker test code
int main(void) {
	Poker poker;
	poker.dealHand();
	pokerHands(poker);
	pokerStats(poker);
	return EXIT_SUCCESS;
} //prev percentage, current percentage, abs diff is < 1*10^-5
