matrix.exe: assign3.cc assign3.h
	g++ -std=c++11 -Wall -Wextra -pedantic -o assign3.exe assign3.cc

clean:
	rm *.exe
