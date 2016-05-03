../obj/opt/Styler.o: Styler.cpp Styler.h global.h
	g++ -Wall -Werror -Wshadow -pedantic -I/usr/local/include -I../../../src -std=gnu++11 -O3 -c Styler.cpp -o ../obj/opt/Styler.o
