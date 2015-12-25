#include "GlobalHeader.h"

Peice::Peice()
{
}

Peice::Peice(PeiceColor theColor)
{
	color = theColor;
	/*
	Debug
	switch (color)
	{
	case white:
		cout << "\nWhite Square";
		break;
	case black: 
		cout << "\nBlack Square";
		break;
	default:
		break;
	}
	*/
	Protection = false;
	Blocking = false;
}

Peice::~Peice()
{
}

PeiceColor Peice::getColor()
{
	return color;
}

bool Peice::isProtected()
{
	return Protection;
}

void Peice::setProtected(bool shouldProtect)
{
	Protection = shouldProtect;
}

void Peice::setBlocking(bool willBlock)
{
	Blocking = willBlock;
}

void Peice::setBoardIndex(int newIndex)
{
	boardIndex = newIndex;
}

int Peice::getBoardIndex()
{
	return boardIndex;
}


