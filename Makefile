all:	main game 

main: main.cpp sodoku.h
	g++ main.cpp -o main

game: game.cpp sodoku.h
	g++ game.cpp -o game

clean: 
	rm *.o main
	rm *.o game

