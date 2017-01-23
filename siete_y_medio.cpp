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
	
	
	Player player1(100);
	char ans = 'y';
	int bet = 0;
	while (player1.cash() > 0)
	{
		do  
		{
			cout << "Cash: " << player1.cash() << ". Enter Bet: ";
			cin >> bet;
			cin.ignore(32767, '\n');
		} while (bet > player1.cash());

		while (ans = 'y' && player1.value_hand() < 7.5)
		{
			cout << "Cards:	\n";
			player1.print_hand();
			do 
			{
				cout << "Your total is: " << player1.value_hand() << ". " << "Do you want another card?";
				cin >> ans;
				cin.ignore(32767, '\n');
			} while ((ans != 'y') &&  (ans != 'n'));
			if (ans == 'y')
			{
				player1.update_hand();
			}
			else
				break;
		}
		player1.reset_hand();
		player1.cash() -= 10;
	}

	

	return 0;
}

