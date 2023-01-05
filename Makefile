all: compile

compile:
	g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -o main -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
	./main