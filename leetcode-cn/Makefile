CXX=g++
CXX_FLAGS=-g -fPIC -Wall -Wextra -pipe -Wno-unused
CXX_INC= -I.
CXX_LINK=-Xlinker "-(" \
  -lpthread \
  -Xlinker "-)"

all: test.cpp *.cpp
	$(CXX) $^ $(CXX_INC) $(CXX_LINK) $(CXX_FLAGS) -o $@

test: test.cpp *.cpp
	$(CXX) test.cpp $(CXX_INC) $(CXX_LINK) $(CXX_FLAGS) -o $@

clean:
	-rm -f *.o *.a test all
