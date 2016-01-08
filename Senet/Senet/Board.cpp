#include "GlobalHeader.h"
Board::Board()
{
	//cout << "board constructor\n";
	for (int c = 0; c < 30; c++)
	{
		BoardSquare* aSquare = new BoardSquare(c);
		theBoard[c] = aSquare;
	}
}



Board::~Board()
{
}

string Board::boardString()
{
	string aString = "\n";
	aString += "---------------------\n|";
	for (int c = 0; c < 10; c++)
	{
		aString += theBoard[c]->getDisplaySquare();
		aString += '|';
	}
	aString += "\n---------------------\n|";
	for (int c = 19; c > 9; c--) {
		aString += theBoard[c]->getDisplaySquare();
		aString += '|';
	}
	aString += "\n---------------------\n|";
	for (int c = 20; c < 30; c++)
	{
		aString += theBoard[c]->getDisplaySquare();
		aString += '|';
	}
	aString += "\n---------------------\n";
	return aString;
}

void Board::setUpGameState()
{
	//cout << "Setting Up Game State";
	Peice* p;
	for (int c = 0; c < 10; c++)
	{
		if (c % 2 == 0)
		{
			p = new Peice(white);
		}
		else
		{
			p = new Peice(black);
		}
		theBoard[c]->movePeiceIntoSquare(p);
		theBoard[c]->setPeiceBoardIndex(c);
	}

}

bool Board::isSpaceOpenToPeiceOfColorOnSpace(int nextSquare, PeiceColor color, int currentSquare)
{
	if (!theBoard[nextSquare]->isOpen()) {
		if (theBoard[nextSquare]->colorOfOccupyingPeice() == color) {
			return false;
		}
		else
		{
			if (theBoard[nextSquare]->isPeiceProtected())
			{
				return false;
			}
			for (int c = currentSquare; c <= nextSquare; c++)
			{
				if (theBoard[c]->isBlocked() && theBoard[c]->colorOfOccupyingPeice() != color) {
					return false;
				}
			}
		}
	}
	return true;
}

void Board::movePeiceFromSquareToSquare(int square1, int square2)
{
	//Debug
	//cout << "\nMoving Peice from Square " << square1 << " To Square " << square2;
	theBoard[square2]->movePeiceIntoSquare(theBoard[square1]->movePeiceOutOfSquare());
	theBoard[square2]->setPeiceBoardIndex(square2);
}

PeiceColor Board::getColorOfPeiceAtIndex(int index)
{
	return theBoard[index]->colorOfOccupyingPeice();
}

void Board::scanForBlocksAndProtection()
{
	for each (BoardSquare* square in theBoard) {
		square->setPeiceBlocking(false);
		square->setPeiceProtected(false);
	}
	for (int c = 0; c < 29; c++) {
		if ((!(theBoard[c]->isOpen())) && (!(theBoard[c + 1]->isOpen()))) {
			if (theBoard[c]->colorOfOccupyingPeice() == theBoard[c + 1]->colorOfOccupyingPeice()) {
				theBoard[c]->setPeiceProtected(true);
				theBoard[c + 1]->setPeiceProtected(true);
			}
		}
	}
	for (int c = 0; c < 28; c++) {
		if ((!(theBoard[c]->isOpen())) && (!(theBoard[c + 1]->isOpen())) && (!(theBoard[c + 2]->isOpen()))) {
			if ((theBoard[c]->colorOfOccupyingPeice() == theBoard[c + 1]->colorOfOccupyingPeice()) && (theBoard[c]->colorOfOccupyingPeice() == theBoard[c + 2]->colorOfOccupyingPeice())) {
				theBoard[c]->setPeiceBlocking(true);
				theBoard[c + 1]->setPeiceBlocking(true);
				theBoard[c + 2]->setPeiceBlocking(true);
			}
		}
	}
}
