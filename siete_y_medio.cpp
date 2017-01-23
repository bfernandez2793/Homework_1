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
	
	/*Hand hand;
	for (int i = 0; i < 5; ++i)
		hand.update_hand();
	hand.print_hand();
	cout << hand.value_hand();
	*/
	Player player1;
	cout << player1.cash() << "\n";
	player1.cash() = 5;
	cout << player1.cash() << "\n";
	return 0;
}

