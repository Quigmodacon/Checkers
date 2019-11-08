

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
} 
// </FUNCTION>
//
// <FUNCTION = randomizeTurnStart>
// <PARAMETERS>
//
// </PARAMETERS>
void board::randomizeTurnStart() {
	
}
// </FUNCTION>
