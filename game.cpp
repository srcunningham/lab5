/* Sara Cunningham, game.cpp
Use of the Puzzle glass to play a game of Sodoku
Lab 5, 2/26/2015 */

#include <iostream>
#include "sodoku.h"
using namespace std;

int main() {

  cout << "Welcome to Sodoku!" << endl;

  Puzzle<int> board; 	// sodoku board of ints
  
  do {
  	board.display(); // display the current unsolved board
  	board.makeMove(); // add number
  } while ( !board.isComplete());  // keep doing this until the board is complete 

  cout << "Congratualtions! You solved the puzzle!" << endl;

}


