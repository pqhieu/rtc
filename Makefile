CFLAGS=-std=c++11 -Wall -Werror -O3


all: run

run: build
	./rtc > out.ppm

build: main.cpp
	$(CXX) $(CFLAGS) main.cpp -o rtc

show: run
	@ (open out.ppm > /dev/null 2>&1 & )

clean:
	$(RM) rtc out.ppm
