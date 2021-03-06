/* Sara Cunningham, sodoku.h 
Header and implementation file for Puzzle class
Lab 5, 2/26/2015 */

#ifndef SODOKU_H
#define SODOKU_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

template <typename T>
class Puzzle{

  public:
	
	Puzzle();	 		// constructor
	void display();	 		// member function to display
	void makeMove(); 	 	// member function to update board based on player move
	bool validRow(int, T);		// member function to check valid row
	bool validCol(int, T);		// member function to check valid column
  	bool validBox(int, int, T);	// member function to check valid Box
	bool isComplete();		// member function to check if puzzle is complete

  private:

	vector<vector <T> > puzzle; 	

};

// counstructor
template<typename T>
Puzzle<T>::Puzzle(){

  // user input filename 
  string fileName;
  cout << "Please enter a file name: ";
  cin >> fileName;
  
  // open file
  ifstream inFile;
  inFile.open(fileName.c_str());

  // read in file
  T tempVar;
  vector<T> tempVec;

  while(!inFile.eof()){ //while the file in not at the end
	for(int i = 0; i < 9; i++){
		inFile >> tempVar;
		tempVec.push_back(tempVar);
	}
	puzzle.push_back(tempVec);
	tempVec.clear();
  }

}

// templated member function to display sodoku board
template<typename T>
void Puzzle<T>::display(){

  // note extra cout lines for formatting 3x3 boxes 

  cout << " ------- ------- -------" << endl;

  for (int i = 0; i < 9; i++){
	cout << "| ";
	for ( int j = 0; j < 9; j++){
		cout << puzzle[i][j] << " "; // display index ixj of puzzle 2D vector 
		if (j % 3 == 2){ // create boxes of 9
			cout << "| ";
		}
	}
	cout << endl;
	if (i % 3 == 2){
		cout << " ------- ------- -------" << endl; // create boxes of 9
	}
  }  

}

// templated member function to take user input to update board
template<typename T>
void Puzzle<T>::makeMove(){

   int n, r, c; 

   // get value from user
   cout << "What number would you like to add to the board? "; 
   cin >> n;

  // check for valid input
  if ( n < 1 || n > 9){
	   do {
		cout << "Invalid input.  Please input a number between 1 and 9: ";
		cin >> n;
	  } while ( n < 1 || n > 9); 
  }
  // get position from user
   cout << "Where would you like to place your number (row column) [1-9]? ";
   cin >> r >> c;
  // check for valid input
  if ( r < 1 || r > 9 || c < 1 || c > 9){
   	do {
		cout << "Invalid input. Please input integers between 1 and 9." << endl;
		cout << "Where would you like to place your number (row column) [1-9]? ";
		cin >> r >> c;
	  } while ( r < 1 || r > 9 || c < 1 || c > 9);
  }
  // check to see if this is a valid placement 
  if (validRow(r-1,n) && validCol(c-1,n) && validBox(r-1,c-1,n) ){
	puzzle[r-1][c-1] = n; // it is so place number here
  }else{
	cout << "Cannot place this here." << endl; // its not so display erro
  }


}

// member function to make sure there is not inputed value in that row
template<typename T> 
bool Puzzle<T>::validRow(int r, T input){
 
  for (int i = 0; i < 9; i++){
	if (puzzle[r][i] == input)
		return false;
  }

  return true;


}

// member function to make sure there is no inputed value in that column
template<typename T>
bool Puzzle<T>::validCol(int c, T input){

  for (int i=0; i < 9; i++){
	if (puzzle[i][c] == input)
		return false;
  }

  return true;
 
}

// member function to make sure there is no umputed value in that box
template<typename T>
bool Puzzle<T>::validBox(int r, int c, T input){

  if (r < 3 && c < 3){ // TLHC
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }

  if ( r < 3 && c < 6 && c > 2 ) { // MLH
	for (int i = 0; i < 3; i++){
		for (int j = 3; j < 6; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }

  if (r < 3 && c > 5 ) { // BLHC
	for (int i = 0; i < 3; i++){
		for (int j = 6; j < 9; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }

  if (r > 2 && r < 6 && c < 3 ){ //TM
	for (int i = 3; i < 6; i++){
		for (int j = 0; j < 3; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }

  if (r > 2 && r < 6 && c > 2 && c < 6){ // middle
	for (int i = 3; i < 6; i++){
		for (int j = 3; j < 6; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }

  if (r > 2 && r < 6 && c > 5) { //BM
	for (int i = 3; i < 6; i++){
		for (int j = 6; j < 9; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }

  if (r > 5 && c < 3) { // TRHC
	for (int i = 6; i < 9; i++){
		for (int j = 0; j < 3; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }

  if (r > 5 && c > 2 && c < 6) { //MR
	for (int i = 6; i < 9; i++){
		for (int j = 3; j < 6; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }

  if (r > 5 && c > 5) { // BRHC
	for (int i = 6; i < 9; i++){
		for (int j = 6; j < 9; j++){
			if (puzzle[i][j] == input){
				return false;
			} 	
		}
	}
  return true;
  }


}

// member function to determine when the puzzle is complete
template<typename T>
bool Puzzle<T>::isComplete(){

  for (int i =0; i < 9; i++){
	for (int j = 0; j < 9; j++){
		if(puzzle[i][j] == 0){
			return false;
		} 
	}
  }
  
  return true;
}


#endif
