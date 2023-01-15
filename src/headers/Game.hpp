
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

    // Create a button object
    sf::RectangleShape button;
    button.setSize(sf::Vector2f(200, 50));
    button.setPosition(WINDOW_WIDTH - 210, WINDOW_HEIGHT - 80);
    button.setFillColor(sf::Color::White);
    button.setOutlineThickness(2);
    button.setOutlineColor(sf::Color::Black);

    // Create a button text object
    sf::Text buttonText;
    buttonText.setFont(gui.font);
    buttonText.setString("Send");
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(button.getPosition().x + button.getSize().x / 2 - buttonText.getGlobalBounds().width / 2,
                           button.getPosition().y + button.getSize().y / 2 - buttonText.getGlobalBounds().height / 2);

    while (window.isOpen()) {
        sf::Event event;
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
                    // Handle other input
                } else {
                    userInput += event.text.unicode;
                    gui.userText.setString(userInput);
                }
            }
            // Handle button press event
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    // Handle button press
                    string response = chatbot.respond(userInput);
                    gui.chatbotText.setString(response);
                    // Reset the user input
                    userInput.clear();

                    userTyping = true;
                    gui.userText.setString(userInput);
                }
            }
            // Handle button hover
            if (button.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                button.setFillColor(sf::Color(200, 200, 200));
            } else {
                button.setFillColor(sf::Color::White);
            }
        }

        // Clear the window
        window.clear();

        // Draw the input box
        window.draw(gui.inputBox);
        // Only draw the placeholder text if the user hasn't started typing
        if (userInput.empty())
            window.draw(gui.placeholderText);
        // Draw the user text
        window.draw(gui.userText);
        // Draw the chatbot text
        window.draw(gui.chatbotText);
        // Draw the button
        window.draw(button);
        // Draw the button text
        window.draw(buttonText);

        // Display the window
        window.display();
    }
}
