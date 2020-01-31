
#ifndef CHECKERS_HPP_
#define CHECKERS_HPP_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

class board {
public:
	board(int size);
	void randomizeTurnStart(); // randomizes which side starts
	void printBoard(); // prints board
	void movePiece(); // moves a piece

private:
	void selectPiece(); // used in movePiece(), selects piece to move
	void selectMoveTo(); // used in movePiece(), selects target square
	bool check(); // checks if square is a valid move (diagonal, not occupied)
	bool checkJump(); // checks if a jump is being made
	void takePiece(); // if checkJump() remove piece from board

	std::vector< std::vector<square*> > gameboard;
	char turn;
	int boardSize; // Not including boarders
	const int pieceCount = 24;
	piece* selectedPi;
	square* selectedSq;
	std::vector<piece*> pieces;
};

class square {
public:
	square(char color, int x, int y);
	void occupation(bool status, char team);
	bool occupied() const {return occupied;}
	char getColor() const {return color;}
	piece* occupier() {return onSquare;}
	bool occupierKinged() const {return onSquare -> isKinged();}

private:
	piece* onSquare;
	char color;
	bool occupied;
	int x, y;
};

class piece {
public:
	piece(char team, int x, int y);
	void king();
	bool isKinged() {return kinged;}
	char getTeam() {return team;}
	void move(int x, int y);

private:
	square* onSquare;
	int x, y;
	char team; // X or O
	bool kinged; // True changes char to K or Q

};

// pieces will be X or O, and K or Q For determining side and kingliness.
//
// +-+-+-+-+-+-+-+-+
// | | | | | | | | |
// +-+-+-+-+-+-+-+-+
// | | | | | | | | |
// +-+-+-+-+-+-+-+-+
// | | | | | | | | |
// +-+-+-+-+-+-+-+-+
// | | | | | | | | |
// +-+-+-+-+-+-+-+-+
// | | | | | | | | |
// +-+-+-+-+-+-+-+-+
// | | | | | | | | |
// +-+-+-+-+-+-+-+-+
// |X|#|X|#|X|#|X|#|
// +-+-+-+-+-+-+-+-+
// |#|X|#|X|#|X|#|X|
// +-+-+-+-+-+-+-+-+

#endif
