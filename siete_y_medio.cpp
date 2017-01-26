#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
#include <vector>
using namespace std;
// Global constants (if any)
// Non member functions declarations (if any)
// Non member functions implementations (if any)
// Stub for main
int main() {
	
	Player player1(100);//inititalize player with 100 dollars
	Player dealer;
	char ans = 'y';
	int bet = 0;
	int loses = 0;
	while (player1.cash() > 0 && loses < 900)
	{
		/************************************************
		PLAYER
		*************************************************/
		do
		{
			cout << "Cash: " << player1.cash() << ". Enter Bet: ";
			cin >> bet;
			cin.clear();
			cin.ignore(32767, '\n');
		} while (bet > player1.cash());

		while (ans = 'y' && player1.value_hand() < 7.5)
		{
			cout << "Your Cards:	\n";
			player1.print_hand();
			do
			{
				cout << "Your total is: " << player1.value_hand() << ". " << "Do you want another card?";
				cin >> ans;
				cin.ignore(32767, '\n');
			} while ((ans != 'y') && (ans != 'n'));

			if (ans == 'y')
			{
				player1.update_hand();
			}
			else
				break;
		}
		cout << "Your Cards:	\n";
		player1.print_hand();
		cout << "Your total is: " << player1.value_hand() << "\n";
		/***********************************************************
		DEALER
		***********************************************************/
		
		while (dealer.value_hand() < 5.5 )
		{
			cout << "Dealer's cards: \n";
			dealer.print_hand();
			cout << "The dealer's total is: " << dealer.value_hand() << "\n";
			dealer.update_hand();
		}
		cout << "Dealer's cards: \n";
		dealer.print_hand();
		cout << "The dealer's total is: " << dealer.value_hand() << "\n";

		if (player1.value_hand() > 7.5)
		{
			cout << "Dealer Wins \n";
			player1.cash() -= bet;
		}
		else if (dealer.value_hand() > 7.5)
		{
			cout << "You Win \n";
			loses -= bet;
			player1.cash() += bet;
		}
		else
		{
			if (player1.value_hand() < dealer.value_hand())
			{
				cout << "Dealer Wins \n";
				player1.cash() -= bet;
			}
			else if (player1.value_hand() == dealer.value_hand())
				cout << "Tie! Nobody Wins! \n";
			else
			{
				cout << "You Win \n";
				player1.cash() += bet;
				loses -=  bet;
			}
		}
		player1.reset_hand();
		dealer.reset_hand();
	}
	cout << "\n\n Game Over!!!\n";
	return 0;
}

