all: pole.exe run

pole.exe: pole.o game.o yakubovich.o
	g++ pole.o game.o yakubovich.o -o pole.exe

pole.o: pole.cpp
	g++ -c pole.cpp -o pole.o

game.o: game.cpp
	g++ -c game.cpp -o game.o

yakubovich.o: yakubovich.cpp
	g++ -c yakubovich.cpp -o yakubovich.o

run: pole.exe
	./pole.exe