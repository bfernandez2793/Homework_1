#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}
// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}
// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}
// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	return "";
}
// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	return "";
}
// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}
//get the value of the card
double Card::get_value() const {
	int value = get_rank();
	if (value < 8)
		return value;
	else
		return 0.5;

}
// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}
/* *************************************************
Hand class
************************************************* */
// Implemente the member functions of the Hand class here.
//hand constructor
Hand::Hand() {
	update_hand();
}
//get another card
void Hand::update_hand(){
	//get another card
	Card new_card;
	_hand.push_back(new_card);
	value_of_hand += new_card.get_value();
}
//return the value of the hand
void Hand::print_hand() {
	//output players hand
	for (size_t i = 0; i < _hand.size(); ++i)
		cout << "\t" << _hand[i].get_spanish_rank() << "\n";
}
double Hand::value_hand() const {
	return value_of_hand;
}
//reset the hand
void Hand::reset_hand() {
	_hand.clear();
	value_of_hand = 0;
	update_hand();
}
//print hand
ostream& operator<<(ostream& out, const Hand& hand)
{
	//output players hand
	for (size_t i = 0; i < hand._hand.size(); ++i)
		out << "\t" << hand._hand[i].get_spanish_rank() << "\n";
	return out;
}
/* *************************************************
Player class
************************************************* */
// Implemente the member functions of the Player class here.
Player::Player(int m) {
	money = m;
}
int& Player::cash() {
	return money;
}
