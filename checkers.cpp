

#include "checkers.hpp"

// <BEGIN>
// <CLASS = board>
/////////////////////////////////////////////////
// Board Class
/////////////////////////////////////////////////

// <FUNCTION = board {constructor}>
// <PARAMETERS>
// size must be even number
// </PARAMETERS>
board::board(int size = 8) {
	boardSize = size;
	bool isEven = true; // used to check every other tile for correct coloring
	for (int col = 0; col < boardSize; col++) { // columns, or x coord
		gameboard.push_back(vector<square*>); // pushs 1 vector for every col
		for (int row = 0; row < boardSize; col++) { // rows, or y coord
			if (isEven) { // checking for tile color
				gameboard[col].push_back(new square(' ', col, row)); // 'white' tile pushed back
				isEven = false; // swap to next color
			}
			else {
				gameboard[col].push_back(new square('#', col, row)); // 'black' tile pushed
				isEven = true; // swap to next color
			}
		}
		if (isEven) // ensure to rows don't have touching colors
			isEven = false;
		else
			isEven = true;
	}
	for (int i = 0; i < pieceCount; i++){
		pieces.push_back(new piece(
	}
} 
// </FUNCTION>
//
// <FUNCTION = randomizeTurnStart>
// <PARAMETERS>
//
// </PARAMETERS>
void board::randomizeTurnStart() {
	srand();
	int randNum = rand() % 2;
	switch(randNum) {
	case 0: turn = 'o'; break;
	case 1: turn = 'x'; break;
	}
}
// </FUNCTION>
//
// <FUNCTION = printBoard>
// <PARAMETERS>
//
// </PARAMETERS>
void board::printBoard() {
	isBorderRow = true;
	isBorderCol = true;
	int sizeRow = 0;
	int sizeCol = 0;
	for (int row = 0; row < boardSize*2+1; row++) {
		for (int col = 0; col < boardSize*2+1; col++) {
			if (isBorderRow) {
				if (row % 2 == 0)
					std::cout << '+';
				else
					std::cout << '-';
				continue;
			}
			else if (isBorderCol) {
				if (col % 2 == 0)
					std::cout << '+';
				else
					std::cout << '-';
				isBorderCol = false;
				continue;
			}
			else {
				if (!gameboard[sizeRow][sizeCol].occupied()) {
					std::cout << gameBoard[sizeRow][sizeCol] -> color();
				}
				else {
					std::cout << gameboard[sizeRow][sizeCol] -> occupier() -> team();
				}
				sizeCol++;
			}
			isBorderCol = true;
		}
		std::cout << '\n';
		sizeRow++;
	} 
}
// </FUNCTION>
//
// <FUNCTION = movePieve>
// <PARAMETERS>
//
// </PARAMETERS>
void movePiece() {
	
}
// </FUNCTION>
