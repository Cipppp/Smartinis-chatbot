
#include "./types.hpp"

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 1200;

//* Function to initialize the font and return it
GUI initializeGUI(sf::RenderWindow& window) {
    GUI gui;

    //? Load the font
    if (!gui.font.loadFromFile("src/fonts/arial.ttf")) {
        cout << "Error loading font" << endl;
    }

    //? Set the window size and title
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chatbot");

    //? Create a graphical text to display on screen for the user input
    gui.userText.setFont(gui.font);
    gui.userText.setFillColor(sf::Color::White);

    //? Create a graphical text to display on screen for the chatbot response
    gui.chatbotText.setFont(gui.font);
    gui.chatbotText.setFillColor(sf::Color::White);

    //? Create a graphical text to display on screen for the placeholder text
    gui.placeholderText.setFont(gui.font);
    gui.placeholderText.setFillColor(sf::Color(200, 200, 200));
    gui.placeholderText.setString("Type your message here...");

    //? Create a graphical rectangle to display on screen for the user input
    gui.inputBox.setSize(sf::Vector2f(WINDOW_WIDTH - 20, 60));
    gui.inputBox.setFillColor(sf::Color(0, 0, 0, 180));
    gui.inputBox.setOutlineThickness(4);
    gui.inputBox.setOutlineColor(sf::Color::White);

    //? Set the position of the input box based on the scale factor
    gui.inputBox.setPosition(10, (WINDOW_HEIGHT - 100));
    gui.placeholderText.setPosition(gui.inputBox.getPosition().x + 10, gui.inputBox.getPosition().y + 5);
    gui.userText.setPosition(10, WINDOW_HEIGHT - 100);
    gui.chatbotText.setPosition(10, (WINDOW_HEIGHT - 700));

    //? Calculate the scale factor based on the current window size
    float scaleX = static_cast<float>(window.getSize().x) / WINDOW_WIDTH;
    float scaleY = static_cast<float>(window.getSize().y) / WINDOW_HEIGHT;

    //? Set the scale of the input box and the text objects
    gui.inputBox.setScale(scaleX, scaleY);
    gui.placeholderText.setScale(scaleX, scaleY);
    gui.userText.setScale(scaleX, scaleY);
    gui.chatbotText.setScale(scaleX, scaleY);

    return gui;
}

void initializeGame(GUI& gui, sf::RenderWindow& window) {
    Chatbot chatbot;

    // Set the default response
    chatbot.setDefaultResponse("I'm sorry, I don't know how to respond to that.");

    // Add a new response to the response map
    chatbot.addResponse("how are you", "I'm just a chatbot, so I don't have feelings. But I'm functioning properly.");

    // Create a string to hold the user input
    string userInput;
    bool userTyping = true;

    while (window.isOpen()) {
        sf::Event event;
        // Process events (user input)
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            // Handle user input text events (typing)
            else if (event.type == sf::Event::TextEntered) {
                // Handle backspace
                if (event.text.unicode == 8 && userInput.length() > 0) {
                    userInput.erase(userInput.length() - 1, 1);
                    gui.userText.setString(userInput);
                    // Handle enter key (send message)
                } else if (event.text.unicode == 10) {
                    userTyping = false;
                    // Handle all other characters
                } else if (event.text.unicode < 128) {
                    userInput += static_cast<char>(event.text.unicode);
                    gui.userText.setString(userInput);
                }
            }
        }
        // If the user has finished typing, get the chatbot response and reset the user input
        if (!userTyping) {
            // Get the chatbot response and display it
            string chatbotResponse = chatbot.getResponse(gui.userText.getString());
            // If the chatbot response is empty, display a default message
            gui.chatbotText.setString(chatbotResponse);
            // Reset the user input
            userInput.clear();
            // Reset the user text
            gui.userText.setString(userInput);
            userTyping = true;
        }

        window.clear();
        window.draw(gui.inputBox);
        // Only draw the placeholder text if the user hasn't started typing
        if (userInput.empty())
            window.draw(gui.placeholderText);
        window.draw(gui.userText);
        window.draw(gui.chatbotText);
        window.display();
    }
}