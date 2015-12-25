#include "GlobalHeader.h"


BoardSquare::BoardSquare() 
{
	BoardSquare(0);
}

BoardSquare::BoardSquare(int sqID)
{
	squareID = sqID;
	switch (squareID)
	{
	case 25:
	case 27:
	case 28:
		SafeSquare = true;
		break;
	default:
		SafeSquare = false;
		break;
	}
}

BoardSquare::~BoardSquare()
{
}

bool BoardSquare::isSquareSafe()
{
	return SafeSquare;
}

bool BoardSquare::isBlocked()
{
	return Blocked;
}

bool BoardSquare::isOpen()
{
	return !occupied;
}

void BoardSquare::movePeiceIntoSquare(Peice* aPeice)
{
	//Debug
	//string aString = "";

	PeiceInSquare = aPeice;
	occupied = true;
	/*
	Also debug
	switch (PeiceInSquare->getColor())
	{
	case white: 
		aString = "White";
		break;
	case black:
		aString = "Black";
		break;
	default:
		break;
	}
	cout << "\nA " << aString << " Peice Moved Peice Into Square: " << squareID;
	*/
}

char BoardSquare::getDisplaySquare()
{
	if (!occupied) {
		if (squareID == 14){
			return 'Y';
		}
		else if (squareID == 25){
			return 224;
		} 
		else if (squareID == 26) {
			return 126;
		}
		else if (squareID == 27) {
			return '@';
		}
		else if (squareID == 28) {
			return 'h';
		}
		else
		{
			return ' ';
		}
	}
	else if (PeiceInSquare->getColor() == black){
		return 'U';
	}
	else if (PeiceInSquare->getColor() == white) {
		return 'A';
	}
	return 0;
}

Peice * BoardSquare::movePeiceOutOfSquare()
{
	Peice* tempPointer = PeiceInSquare;
	PeiceInSquare = nullptr;
	occupied = false;
	Blocked = false;
	return tempPointer;
}

PeiceColor BoardSquare::colorOfOccupyingPeice()
{
	return PeiceInSquare->getColor();
}

bool BoardSquare::isPeiceProtected()
{
	return PeiceInSquare->isProtected();
}

void BoardSquare::setPeiceBoardIndex(int newIndex)
{
	PeiceInSquare->setBoardIndex(newIndex);
}
