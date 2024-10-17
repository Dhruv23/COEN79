/*
 * Name: Dhruv Patel
 * Email: ddpatel@scu.edu
 */
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include "card_ddpatel.h"
#include "deck_ddpatel.h"
#include "poker_ddpatel.h"

using namespace std;
using namespace lab2_ddpatel;

namespace lab2_ddpatel{
	Poker::Poker() : deck(), hand{Card(0,0), Card(0,0), Card(0,0), Card(0,0), Card(0,0)}{}
	
	
	std::array<Card, 5> Poker::getHand(){
		return this->hand;
	}

	void Poker::assignHand(std::array<Card, 5> input){
		 for (int i = 0; i < 5; ++i) {
            this->hand[i] = input[i];
		}
	}
	void Poker::dealHand() {
        // Deal a hand of 5 cards from the deck
		for (int i = 0; i < 5; ++i) {
			hand[i] = deck.deal();
			
		} 
	}
    

	// so that we can simply "cout << " a poker hand
	std::ostream& operator<<(std::ostream& os, const Poker& p){
        for (const auto& card : p.hand) {
            os << card << ", "; 
        }
        return os;
    }

	int Poker::rankHand(std::array<Card, 5> input){
        int i, j, sameAsFirstSuit, sameAsFirstRank, sameAsSecondRank, sameAsThirdRank, sameAsFourthRank;
        int ranks[5];
        int suits[5];
        bool pairFirst, tripleFirst, tripleSecond, tripleThird, straight;
        straight = false;
        for(i=0; i<5; i++){
            ranks[i] = input[i].getRank();
            suits[i] = input[i].getSuit();
            //cout << ranks[i] << " " << suits[i] << endl;
        }
        sameAsFirstSuit = 0;
        sameAsFirstRank = 0;
        sameAsSecondRank = 0;
        sameAsThirdRank = 0;
        sameAsFourthRank = 0;

        //sort array of ranks 
        std::sort(ranks, ranks + 5);
        std::sort(suits, suits + 5);

    //Check if the difference between each adjacent pair is 1
        for (int i = 0; i < 4; ++i) {
            if (ranks[i + 1] - ranks[i] != 1) {
                break; // Not a straight
            }else if(i == 3){
                straight = true;
                
            }
            
        }
        //check for flush 
        for (i = 1; i < 5; ++i) {
            if (suits[i] == suits[0]) {
                sameAsFirstSuit++;
            }
            //cout << "Same as first suit: " << sameAsFirstSuit << endl;
        }
        //count number that are same as first card's rank
        for (i = 1; i < 5; ++i) {
            if (ranks[i] == ranks[0]) {
                sameAsFirstRank++;
            }
        }
		//cout << "Same as first rank: " << sameAsFirstRank << endl;
        if(ranks[0] != ranks[1]){
            //count number that are same as second card's rank
            for (i = 2; i < 5; ++i) {
                if (ranks[i] == ranks[1]) {
                    sameAsSecondRank++;
                }
            }
        }
		//cout << "Same as second rank: " << sameAsSecondRank << endl;
        if(ranks[0] != ranks[2] && ranks[1]!= ranks[2]){
            for (i = 3; i < 5; ++i) {
                if (ranks[i] == ranks[2]) {
                    sameAsThirdRank++;
                }
            }
        }
		//cout << "Same as third rank: " << sameAsThirdRank << endl;
        if (ranks[0] != ranks[3] && ranks[1] != ranks[3] && ranks[2] != ranks[3]) {
            // Count number that are same as fourth card's rank
            for (i = 4; i < 5; ++i) {
                if (ranks[i] == ranks[3]) {
                    sameAsFourthRank++;
                }
            }
        }
		//cout << "Same as fourth rank: " << sameAsFourthRank << endl;
        
        
        if(sameAsFirstSuit == 4 && straight == true){
            return Poker::POKER_STRAIGHT_FLUSH;
        }else if(sameAsFirstSuit != 4 && straight == true){
            return Poker::POKER_STRAIGHT;
        }else if(sameAsFirstSuit == 4 && straight == false){
            return Poker::POKER_FLUSH;
        }
        else if(sameAsFirstRank >=3 || sameAsSecondRank >=3 || sameAsThirdRank >=3 || sameAsFourthRank >=3){
            return Poker::POKER_QUAD;
        }
        else if(sameAsFirstRank == 2){
            tripleFirst = true;
                if(sameAsSecondRank == 1 || sameAsThirdRank == 1 || sameAsFourthRank == 1){	
                    return Poker::POKER_FULLHOUSE;
                }else{
                    return Poker::POKER_TRIPLE;
                }
        }else if(sameAsSecondRank == 2){
            tripleSecond = true;
            if(sameAsFirstRank == 1 || sameAsThirdRank ==1  || sameAsFourthRank == 1){
                return Poker::POKER_FULLHOUSE;
            }else{
                return Poker::POKER_TRIPLE;
            }
        }else if(sameAsThirdRank == 2){
            tripleThird = true;
            if(sameAsFirstRank == 1 || sameAsSecondRank ==1 || sameAsFourthRank == 1){
                return Poker::POKER_FULLHOUSE;
            }else{
                return Poker::POKER_TRIPLE;
            }		
        }else if((sameAsFirstRank == 1 && sameAsSecondRank == 1) || (sameAsFirstRank == 1 && sameAsThirdRank == 1) || (sameAsFirstRank == 1 && sameAsFourthRank == 1) || (sameAsSecondRank == 1 && sameAsThirdRank == 1) || (sameAsSecondRank == 1 && sameAsFourthRank == 1) || (sameAsThirdRank == 1 && sameAsFourthRank == 1)){
            return Poker::POKER_2_PAIR;
        }
        else if(sameAsFirstRank == 1 || sameAsSecondRank ==1 ||sameAsThirdRank ==1 || sameAsFourthRank ==1){
            return Poker::POKER_PAIR;
        }
        else if(sameAsFirstRank == 0 && sameAsSecondRank ==0 && sameAsThirdRank ==0 && sameAsFourthRank ==0){
            return Poker::POKER_HIGHCARD;
        }
        else{
            return 0;
        }
        return -1;


        
    }

	
}