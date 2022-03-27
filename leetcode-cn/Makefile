CXX=g++
CXX_FLAGS=-g -fPIC -Wall -Wextra -pipe -Wno-unused -std=c++11
CXX_INC= -I.

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o )

all: $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $^ $(CXX_INC) $(CXX_FLAGS) -c -o $@

test: test.cpp $(SRCS)
	$(CXX) test.cpp $(CXX_INC) $(CXX_FLAGS) -o $@

clean:
	-rm -f *.o *.a test all
