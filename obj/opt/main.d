../obj/opt/main.o: main.cpp global.h Styler.h
	g++ -Wall -Werror -Wshadow -pedantic -I/usr/local/include -I../../../src -std=gnu++11 -O3 -c main.cpp -o ../obj/opt/main.o
