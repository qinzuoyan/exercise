CXX=g++
CXX_FLAGS=-g -fPIC -Wall -Wextra -pipe -Wno-unused
CXX_INC= -I.
CXX_LINK=-Xlinker "-(" \
  -lpthread \
  -Xlinker "-)"

OBJS=test

all: $(OBJS)

test: test.cpp *.cpp
	$(CXX) $^ $(CXX_INC) $(CXX_LINK) $(CXX_FLAGS) -o $@

clean:
	-rm -f *.o *.a $(OBJS)
