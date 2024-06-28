#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

vector<string> zepplinVec = { " "," "," "," "," ","          " }; //Vector for zepplin, I used string so it could be easily displayed and replaced with the game pieces

int player1Score = 6;
int player2Score = 6;

void renderZepplin() { //This displays the zepplin, and the players points, with the pieces on the actual zepplin after every roll
	cout << " __ __ __ __ __ \n"
		<< "|" << zepplinVec[0] << " |" << zepplinVec[1] << " |" + zepplinVec[2] << " |" << zepplinVec[3] << " |" << zepplinVec[4] << " |%\n"
		<< " -- -- -- -- -- \n"
		<< "|" << zepplinVec[5] << "|% \n"
		<< " ---------- \n\n"
		<< "Player 1's Points = ";
	for (int i = 0; i < player1Score; ++i)
		cout << '*';
	cout << "\nPlayer 2's Points = ";
	for (int i = 0; i < player2Score; ++i)
		cout << '^';
	cout << "\n\n";
}

void player1Roll() { //Rolls dice, then changes the zepplinVec based on what the player rolled
	cout << "Player 1, press 'Enter' to roll!\n";
	cin.ignore();
	int dieRoll = rand() % 6 + 1;
	cout << "The roll is: " << dieRoll << "\n";
	if (dieRoll < 6 && zepplinVec[dieRoll - 1][0] == ' ') {
		zepplinVec[dieRoll - 1].replace(0, 1, 1, '*');
		--player1Score;
	}
	else if (dieRoll < 6 && zepplinVec[dieRoll - 1][0] == '^') {
		zepplinVec[dieRoll - 1].replace(0, 1, 1, '*');
		--player1Score;
		++player2Score;
	}
	else if (dieRoll < 6 && zepplinVec[dieRoll - 1][0] == '*') {
	}
	else {
		for (int i = 0; i < 10; ++i) {
			if (zepplinVec[5][i] == ' ') {
				zepplinVec[5].replace(i, 1, 1, '*');
				--player1Score;
				break;
			}
		}
	}
}

void player2Roll() { //Same thing but for Player 2
	cout << "Player 2, press 'Enter' to roll!\n";
	cin.ignore();
	int dieRoll = rand() % 6 + 1;
	cout << "The roll is: " << dieRoll << "\n";
	if (dieRoll < 6 && zepplinVec[dieRoll - 1][0] == ' ') {
		zepplinVec[dieRoll - 1].replace(0, 1, 1, '^');
		--player2Score;
	}
	else if (dieRoll < 6 && zepplinVec[dieRoll - 1][0] == '*') {
		zepplinVec[dieRoll - 1].replace(0, 1, 1, '^');
		++player1Score;
		--player2Score;
	}
	else if (dieRoll < 6 && zepplinVec[dieRoll - 1][0] == '^') {
	}
	else {
		for (int i = 0; i < 10; ++i) {
			if (zepplinVec[5][i] == ' ') {
				zepplinVec[5].replace(i, 1, 1, '^');
				--player2Score;
				break;
			}
		}
	}
}

int main()
{
	srand(time(0));
	cout << "This is the Zepplin Game!\n\nPlayer one's points are rendered using the symbol '*'\n" <<
		"Player Two's points are rendered using the symbol '^'\n" <<
		"Each player will start with 6 points, as you roll, one of your points will go to the space correlated to your roll\non the zepplin.\n" <<
		"If you roll a 5, and the other player already has a point on 5, that point will return to the other player,\nand one of your points will go onto position 5.\n" <<
		"If a player rolls a 6, their point will go to the gondola, and remain there for the rest of the game.\n";
	renderZepplin();
	cout << "Player 1 will roll first, have fun! \n";
	while (player1Score > 0 && player2Score > 0) { //Main flow of the game
		player1Roll();
		renderZepplin();
		if (player1Score == 0)
			goto PLAYER2WIN;
		player2Roll();
		renderZepplin();
		if (player2Score == 0)
			goto PLAYER1WIN;
	}
PLAYER2WIN:
	cout << "Player 2 has won the game! \n";
	goto ENDGAME;
PLAYER1WIN:
	cout << "Player 1 has won the game! \n";
	goto ENDGAME;
ENDGAME:
	return 0;
}