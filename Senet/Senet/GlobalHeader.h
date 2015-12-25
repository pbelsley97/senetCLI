#pragma once
#ifndef GlobalHeader_h
#define GlobalHeader_h

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum PeiceColor
{
	black = 1, white 
};

class Peice
{
public:
	Peice();
	Peice(PeiceColor);
	~Peice();
	PeiceColor getColor();
	bool isProtected();
	void setProtected(bool);
	void setBlocking(bool);
	void setBoardIndex(int);
	int getBoardIndex();

private:
	PeiceColor color;
	bool Protection;
	bool Blocking;
	int boardIndex;
};
class BoardSquare
{
public:
	BoardSquare();
	BoardSquare(int sqID);
	~BoardSquare();
	bool isSquareSafe();
	bool isBlocked();
	bool isOpen();
	void movePeiceIntoSquare(Peice*);
	char getDisplaySquare();
	Peice* movePeiceOutOfSquare();
	PeiceColor colorOfOccupyingPeice();
	bool isPeiceProtected();
	void setPeiceBoardIndex(int);
private:
	bool occupied = false;
	bool SafeSquare;
	int squareID;
	bool Blocked = false;
	Peice* PeiceInSquare;
};

class Game 
{
public:
	Game();
	~Game();
	string getPlayer1Name();
	string getPlayer2Name();
	void setPlayer1Name(string);
	void setPlayer2Name(string);
	bool isItPlayer1sTurn();
	void setPlayer1Turn(bool);
	void togglePlayer1Turn();
	void determineSides();

private:
	string player1Name;
	string player2Name;
	bool player1Turn;

};

class Board
{
public:
	Board();
	~Board();
	string boardString();
	void setUpGameState();
	bool isSpaceOpenToPeiceOfColorOnSpace(int, PeiceColor, int);
	void movePeiceFromSquareToSquare(int, int);
	PeiceColor getColorOfPeiceAtIndex(int);
private:
	BoardSquare* theBoard[30];
};

void drawBoard(Board*);

int getIntInputFromUser();

string getStringInputFromUser();

Game* setUpGameObject();

void printRollForPlayer(int, string);

int getDiceRoll();

void displaySidesAndFirstTurn(Game* );

#endif // GlobalHeader_h
