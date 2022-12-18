# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target
TARGET1 = test
TARGET2 = test2
TARGET3 = test3

all: $(TARGET1)

build: $(TARGET1).cpp
		g++ strings.cpp main.cpp -o $(TARGET1)
makeclean:
		$(RM) $(TARGET1).cpp