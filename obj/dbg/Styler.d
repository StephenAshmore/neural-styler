../obj/dbg/Styler.o: Styler.cpp Styler.h global.h
	g++ -Wall -Werror -Wshadow -pedantic -I/usr/local/include -I../../../src -std=gnu++11 -g -D_DEBUG -c Styler.cpp -o ../obj/dbg/Styler.o
