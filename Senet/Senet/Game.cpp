#include "GlobalHeader.h"

Game::Game()
{
	player1Name = "";
	player2Name = "";
	player1Turn = true;
}

Game::~Game()
{
}

string Game::getPlayer1Name() {
	return player1Name;
}

string Game::getPlayer2Name()
{
	return player2Name;
}

void Game::setPlayer1Name(string newName)
{
	player1Name = newName;
}

void Game::setPlayer2Name(string newName)
{
	player2Name = newName;
}

bool Game::isItPlayer1sTurn()
{
	return player1Turn;
}

void Game::setPlayer1Turn(bool turn)
{
	player1Turn = turn;
}

void Game::togglePlayer1Turn()
{
	player1Turn = !player1Turn;
}

void Game::determineSides()
{
	int roll;
	do {
		roll = getDiceRoll();
		if (player1Turn)
		{
			printRollForPlayer(roll, player1Name);
		}
		else
		{
			printRollForPlayer(roll, player2Name);
		}
		player1Turn = !player1Turn;
	} while (roll != 1);
	player1Turn = !player1Turn;
	displaySidesAndFirstTurn(this);
}
