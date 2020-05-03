CFLAGS=-std=c++11 -Wall -Werror -O3


all: run

run: build
	./rtc > out.ppm

build: main.cpp
	$(CXX) $(CFLAGS) main.cpp -o rtc

clean:
	$(RM) rtc out.ppm
