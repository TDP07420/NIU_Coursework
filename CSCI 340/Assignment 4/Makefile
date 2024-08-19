CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -pedantic -I


all: stack


stack: main.cc rational.cc rational.h stack.h
	g++ $(CXXFLAGS) -o stack main.cc rational.cc

clean:
	rm -f stack


world:

	clean all
