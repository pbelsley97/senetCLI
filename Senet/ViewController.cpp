
#include "GlobalHeader.h"


void drawBoard(Board* theBoard) {
	cout << theBoard->boardString();
}

int getIntInputFromUser()
{
	string stringInput;
	int input;
	bool valid = true;
	do {
		valid = true;
		getline(cin, stringInput);
		try {

			input = stoi(stringInput);
		}
		catch (const invalid_argument& e) {
			cout << "Error! that is not a valid number.\nTry again.\n";
			valid = false;
		}
		catch (const out_of_range& e) {
			cout << "Error! that is not a valid number.\nTry again.\n";
			valid = false;
		}
	} while (!valid);
	
	return input;
}

string getStringInputFromUser()
{
	string aString;
	getline(cin, aString);
	return aString;
}

Game * setUpGameObject()
{
	Game* aGame = new Game();
	cout << "What is player 1's name? ";
	aGame->setPlayer1Name(getStringInputFromUser());
	cout << "\nWhat is player 2's name? ";
	aGame->setPlayer2Name(getStringInputFromUser());
	return aGame;
}

void printRollForPlayer(int roll, string name)
{
	cout << name << " has rolled a " << roll << endl;
}

int getDiceRoll()
{
	int result = 0, temp;
	for (int c = 0; c < 4; c++)
	{
		temp = rand() % 100;
		if (temp < 55)
			result++;

	}
	if (result == 0)
		return 6;
	return result;
}

void displaySidesAndFirstTurn(Game* theGame)
{
	if (theGame->isItPlayer1sTurn()) {
		cout << "Since " << theGame->getPlayer1Name() << " has rolled a 1, they shall go first.\n";
		cout << theGame->getPlayer1Name() << " shall control the black peices, represented by 'U'.\n";
		cout << theGame->getPlayer2Name() << " shall control the white peices, represented by 'A'.\n";
	}
	else
	{
		cout << "Since " << theGame->getPlayer2Name() << " has rolled a 1, they shall go first.\n";
		cout << theGame->getPlayer2Name() << " shall control the black peices, represented by 'U'.\n";
		cout << theGame->getPlayer1Name() << " shall control the white peices, represented by 'A'.\n";
	}
}
