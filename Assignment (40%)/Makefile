all: main clean

main: main.o board.o data.o display.o menus.o
	g++ -o main main.o board.o data.o display.o menus.o

menus.o: lib/menus.cpp lib/menus.hpp
	g++ -c lib/menus.cpp

display.o: lib/display.cpp lib/display.hpp
	g++ -c lib/display.cpp

data.o: lib/data.cpp lib/data.hpp
	g++ -c lib/data.cpp

board.o: lib/board.cpp lib/board.hpp
	g++ -c lib/board.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp

.PHONY: clean
clean:
	rm -rf main.o board.o data.o display.o menus.o