#include <iostream>
#include "Dice.h"
#include "Player.h"
#include <ctime>
using namespace std;

int main() {
	Dice dice1;
	Dice dice2;
	Player player1("È«±æµ¿");
	Player player2("°í±æµ¿");

	srand((unsigned)time(NULL));

	player1.roll(dice1, dice2);
	player2.roll(dice1, dice2);

	if (player1.getTotal() > player2.getTotal()) {
		cout << player1.getName() << "´ÔÀÇ ½Â¸® => ";
		cout << player1.getTotal() << " : " << player2.getTotal() << endl;
	}
	else if (player1.getTotal() < player2.getTotal()) {
		cout << player2.getName() << "´ÔÀÇ ½Â¸® => ";
		cout << player1.getTotal() << " : " << player2.getTotal() << endl;
	}
	else {
		cout << "¹«½ÂºÎ => ";
		cout << player1.getTotal() << " : " << player2.getTotal() << endl;
	}
	return 0;
}