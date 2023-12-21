all: balbes.exe run

balbes.exe: balbes.o shishka.o 
	g++ balbes.o shishka.o -o balbes.exe

balbes.o: balbes.cpp
	g++ -c balbes.cpp -o balbes.o

shishka.o: shishka.cpp
	g++ -c shishka.cpp -o shishka.o

run: balbes.exe
	./balbes.exe