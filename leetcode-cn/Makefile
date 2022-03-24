CXX=g++
CXX_FLAGS=-g -fPIC -Wall -Wextra -pipe -Wno-unused -std=c++11
CXX_INC= -I.

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o )

all: $(OBJS)
	$(CXX) $^ -o all.o

%.o: %.cpp
	$(CXX) $^ $(CXX_INC) $(CXX_FLAGS) -c -o $@

test: test.o $(SRCS)
	$(CXX) test.o -o $@

clean:
	-rm -f *.o *.a test all
