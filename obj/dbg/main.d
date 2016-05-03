../obj/dbg/main.o: main.cpp global.h Styler.h
	g++ -Wall -Werror -Wshadow -pedantic -I/usr/local/include -I../../../src -std=gnu++11 -g -D_DEBUG -c main.cpp -o ../obj/dbg/main.o
