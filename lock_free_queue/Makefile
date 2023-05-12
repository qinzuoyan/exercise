all: test

test: lock_free_queue_test.cc
	g++ -g -o $@ $^ -std=c++11 -lgtest -pthread

clean:
	-rm test
