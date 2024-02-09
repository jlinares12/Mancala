play: main.o game.o player.o
		clang++ main.o game.o player.o -o play

main.cpp: main.cpp
		clang++ -c main.cpp

game.cpp: game.cpp game.h
		clang++ -c game.cpp

player.cpp: player.cpp player.h
		clang++ -c player.cpp

spotless:
		rm *.o