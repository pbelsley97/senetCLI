// Senet.cpp : Defines the entry point for the console application.
//

#include "GlobalHeader.h"


int main()
{
	bool isGameOver = false;
	cout << "Greetings, Pharoh.";
	srand(time(NULL));
	Board* gameBoard = new Board();
	Game* gameState = setUpGameObject();
	gameBoard->setUpGameState();
	drawBoard(gameBoard);
	gameState->determineSides();
	// Game Loop

	if (gameBoard->isSpaceOpenToPeiceOfColorOnSpace(10, gameBoard->getColorOfPeiceAtIndex(9), 9))
	{
		gameBoard->movePeiceFromSquareToSquare(9, 10);
	}	
	drawBoard(gameBoard);
	cin.get();
    return 0;
}

