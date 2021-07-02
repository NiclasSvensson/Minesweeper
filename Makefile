app: main.o board.o square.o resource.o
	g++ main.o board.o square.o resource.o -o app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp constants.h
	g++ -std=c++17 -c main.cpp

board.o: board.cpp board.h resource.cpp resource.h constants.h
	g++ -c board.cpp

square.o: square.cpp square.h
	g++ -c square.cpp

resource.o: resource.cpp resource.h
	g++ -std=c++17 -c resource.cpp

clean:
	rm *.o app
