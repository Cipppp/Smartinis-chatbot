struct GUI {
    sf::Font font;
    sf::Text userText;
    sf::Text chatbotText;
    sf::Text placeholderText;
    sf::RectangleShape inputBox;
    // Add a button to add a new response to the chatbot
    sf::RectangleShape addButton;
    // Button text
    sf::Text buttonText;
};