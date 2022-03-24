CXX=g++
CXX_FLAGS=-g -fPIC -Wall -Wextra -pipe -Wno-unused -std=c++11
CXX_INC= -I.
CXX_LINK=

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o )

all: $(OBJS)
	$(CXX) $^ $(CXX_LINK) -o $@

%.o: %.cpp
	$(CXX) $^ $(CXX_INC) $(CXX_FLAGS) -c -o $@

test: test.cpp *.cpp
	$(CXX) test.cpp $(CXX_INC) $(CXX_LINK) $(CXX_FLAGS) -o $@

clean:
	-rm -f *.o *.a test all
