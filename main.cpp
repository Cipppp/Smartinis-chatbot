#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#include "./src/headers/Chatbot.hpp"
#include "./src/headers/Game.hpp"

int main() {
    //* Create the main window
    sf::RenderWindow window;
    GUI gui = initializeGUI(window);

    //* Start the game
    initializeGame(gui, window);

    return 0;
}
