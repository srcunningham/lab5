/* Sara Cunningham, main.cpp
Driver program to demonstrate Puzzle class 
Lab 5, 2/26/2015 */

#include <iostream>
#include "sodoku.h"
using namespace std;

int main(){
 
  // demonstrate class with integers
  cout << "Use interger file for the Puzzle class. " << endl;
  Puzzle<int> intPuz;
  intPuz.display();

  // demonstrate class with characters
  //cout << "Use puzzle file for the Puzzle classs. "<< endl;
  Puzzle<char> charPuz;
  charPuz.display();
}
