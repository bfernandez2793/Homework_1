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
	while (player1.cash() > 0)
	{ 
	
		while (ans = 'y' && player1.value_hand() < 7.5)
		{
			cout << "Cards:	\n";
			player1.print_hand();
			cout << "would you like another card?";
			cin >> ans;
			if (ans == 'y')
			{
				player1.update_hand();
				cout << "value: " << player1.value_hand() << "\n";
			}
		}
		player1.cash() -= 10;
		cout << "Cash:  " << player1.cash() << "\n";
	}

	

	return 0;
}

