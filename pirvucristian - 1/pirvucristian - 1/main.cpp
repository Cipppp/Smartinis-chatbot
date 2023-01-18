#include <TGUI/TGUI.hpp>
#include <algorithm>
#include <iostream>

#include "SFML/Graphics.hpp"

//* Resolution: Defining the width and height of the window, and the height of the buttons
#define WIDTH 700
#define HEIGTH 1200
#define B_HEIGHT 50

//* Declaring pointers for the textures and font that will be loaded later
sf::Texture* boublePtr;
sf::Font* fontPtr;

//* Struct for message: Defining a struct to hold the message text and a boolean indicating if the message was sent by the user or not
struct Message {
    std::string txt;
    bool isSent;  //? true if the message has been sent by the user, false if the message is sent by the bot
};

//* Helper function to draw speech bubble: Declaring a function that will be used later to draw speech bubbles for the messages
void drawSpeechBouble(sf::RenderWindow& window, sf::Color color, sf::Color txtColor, sf::Vector2f pos, std::string str);

//* Callback function for button and editbox: Declaring a function that will be called when the user presses the send button or the enter key in the edit box
void btnCallback(tgui::EditBox::Ptr eb, std::vector<Message>* msgs);

int main() {
    //* Creating the window for the chatbot
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "iBot", sf::Style::Titlebar | sf::Style::Close);

    //* Loading textures for the logo, speech bubbles, send button, and moon
    sf::Texture logo;
    if (!logo.loadFromFile("logo.png")) {
        std::cout << "Error in loading texture 'logo.png'\n";
        return -1;
    }

    sf::Texture bouble;
    if (!bouble.loadFromFile("bouble.png")) {
        std::cout << "Error in loading texture 'bouble.png'\n";
        return -1;
    }
    boublePtr = &bouble;

    sf::Texture send;
    if (!send.loadFromFile("send.png")) {
        std::cout << "Error in loading texture 'send.png'\n";
        return -1;
    }

    sf::Texture moon;
    if (!moon.loadFromFile("moon.png")) {
        std::cout << "Error in loading texture 'moon.png'\n";
        return -1;
    }

    //* Loading font for text
    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf")) {
        std::cout << "Error in loading font\n";
        return -1;
    }
    fontPtr = &font;

    //* Creating a vector of messages
    std::vector<Message> messages;
    messages.push_back({"Hello", true});
    messages.push_back({"World", true});
    messages.push_back({"Programmed to work", false});
    messages.push_back({"And not to feel", true});

    //* Creating GUI elements using TGUI
    tgui::Gui gui{window};

    //* Creating an edit box for the user to enter their message
    auto editBox = tgui::EditBox::create();
    editBox->setPosition(20, HEIGTH - B_HEIGHT * 2.5 + 40);
    editBox->setTextSize(0);
    editBox->setSize({WIDTH - B_HEIGHT - 10 - 40, B_HEIGHT + 10});
    editBox->setDefaultText("Write message...");

    //* Setting the callback function for when the enter key is pressed or the button is pressed
    editBox->onReturnKeyPress(&btnCallback, editBox, &messages);
    gui.add(editBox, "eb");

    //* Creating a button to send the message
    tgui::Button::Ptr btn = tgui::Button::create();
    btn->setPosition("eb.right", "eb.top");
    btn->setText("");
    btn->setTextSize(0);
    btn->setSize({B_HEIGHT + 10, B_HEIGHT + 10});
    btn->onPress(&btnCallback, editBox, &messages);
    gui.add(btn);

    //* Creating a toggle button to change the color scheme
    auto toggle = tgui::ToggleButton::create("");
    toggle->setTextSize(0);
    toggle->setSize({B_HEIGHT * 2, B_HEIGHT * 2});
    toggle->setPosition(WIDTH - B_HEIGHT * 2 - 40, HEIGTH / 7 / 2 - B_HEIGHT);
    gui.add(toggle);

    //* Current color scheme: Declaring variables to hold the current background, banner, and moon colors
    sf::Color background = sf::Color(0xf5f5f5ff);
    sf::Color banners = sf::Color::White;
    sf::Color moonColor = sf::Color(0x111111ff);

    //* Misc variables: Declaring a variable to hold the position of the screen
    float screenPos = 200.;
    sf::Text textMesure;
    textMesure.setCharacterSize(B_HEIGHT * 0.75);
    textMesure.setFont(font);
    int animPos = 0;
    bool mouseOverMoon = false;

    //* Main loop: The program runs in this loop until the user closes the window
    sf::Clock timer;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseWheelScrolled:
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                        screenPos = std::min(screenPos - event.mouseWheelScroll.delta * 10, 200.f);
                    break;

                case sf::Event::MouseMoved:
                    mouseOverMoon = toggle->isMouseOnWidget(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                    break;
            }

            gui.handleEvent(event);
        }

        //! Dark mode logic: if toggle button is pressed, change background, banner, and moon colors accordingly
        if (toggle->isDown()) {
            background = sf::Color(0x333333ff);
            banners = sf::Color(0x111111ff);
            moonColor = (mouseOverMoon) ? sf::Color(0xddddddff) : sf::Color::White;
        } else {
            background = sf::Color(0xf5f5f5ff);
            banners = sf::Color::White;
            moonColor = (mouseOverMoon) ? sf::Color(0x333333ff) : sf::Color(0x111111ff);
        }

        //! Dot animation logic: logic to animate the dot while the user is typing
        if (editBox->getText() != "" && messages[messages.size() - 1].txt != "          ") {
            messages.push_back({"          ", true});
        } else if (editBox->getText() == "" && messages[messages.size() - 1].txt == "          ") {
            messages.pop_back();
        }

        //* Draw code: Code to draw the elements on the screen
        window.clear(background);

        //* Draw speech boubles: Loop to draw the speech bubbles for all messages
        for (int i = messages.size() - 1; i >= 0; i--) {
            if (messages[i].isSent) {
                textMesure.setString(messages[i].txt);
                drawSpeechBouble(
                    window,
                    sf::Color(0x3888ebff),  // Background color
                    sf::Color(0xffffffff),  // Text color
                    sf::Vector2f(
                        WIDTH - 40 - textMesure.getGlobalBounds().width - B_HEIGHT / 5 * 2,
                        HEIGTH - (screenPos + (messages.size() - i - 1) * (B_HEIGHT + 10))),  // Position
                    messages[i].txt                                                           // Text
                );
            } else {
                drawSpeechBouble(
                    window,
                    sf::Color(0xe4e4e4ff),                                                                 // Background color
                    sf::Color(0x000000ff),                                                                 // Text color
                    sf::Vector2f(20, HEIGTH - (screenPos + (messages.size() - i - 1) * (B_HEIGHT + 10))),  // Position
                    messages[i].txt                                                                        // Text
                );
            }
        }

        //* Draw dots: Code to draw the dots when the user is typing
        if (editBox->getText() != "") {
            sf::Vector2f boublePos(WIDTH - B_HEIGHT * 3 + 25, HEIGTH - screenPos + B_HEIGHT / 2 - 5);
            for (int i = 0; i < 3; i++) {
                sf::CircleShape dot(10);
                dot.setFillColor(sf::Color::White);
                dot.setPosition(sf::Vector2f(
                                    i * 30,
                                    (animPos + i < 50) ? (-sin((animPos + i * 5) * 3.6 * 3.14 / 180) * B_HEIGHT / 4)
                                                       : 0) +
                                boublePos);
                window.draw(dot);
                animPos++;
                if (animPos == 200) animPos = 0;
            }
        }

        //* Draw GUI: Draw the banner, send button, toggle button, and the edit box
        sf::RectangleShape banner_bottom(sf::Vector2f(WIDTH, B_HEIGHT * 2.5));
        banner_bottom.setFillColor(background);
        banner_bottom.setPosition(sf::Vector2f(0, HEIGTH - (B_HEIGHT * 2.5)));
        window.draw(banner_bottom);

        gui.draw();

        sf::RectangleShape sendRect(sf::Vector2f(B_HEIGHT, B_HEIGHT));
        sendRect.setFillColor(sf::Color(0x3888ebff));
        sendRect.setTexture(&send);
        sendRect.setPosition((sf::Vector2f)btn->getPosition() + sf::Vector2f(5, 5));
        window.draw(sendRect);

        // Top banner
        sf::RectangleShape banner_top(sf::Vector2f(WIDTH, HEIGTH / 7));
        banner_top.setFillColor(background);
        window.draw(banner_top);

        sf::RectangleShape logoRect(sf::Vector2f(HEIGTH / 7, HEIGTH / 7));
        logoRect.setTexture(&logo);
        logoRect.setPosition(sf::Vector2f(WIDTH / 2 - HEIGTH / 14, 0));
        window.draw(logoRect);

        // Moon icon
        sf::RectangleShape moonRect(sf::Vector2f(B_HEIGHT * 2 - 30, B_HEIGHT * 2 - 30));
        moonRect.setFillColor(sf::Color(moonColor));
        moonRect.setTexture(&moon);
        moonRect.setPosition((sf::Vector2f)toggle->getPosition() + sf::Vector2f(15, 15));
        window.draw(moonRect);

        window.display();

        while (timer.getElapsedTime().asMilliseconds() < 1000 / 60)
            ;
        timer.restart();
    }

    return 0;
}

//* Helper function to draw speech bubble: Defining the function to draw speech bubbles for the messages
void drawSpeechBouble(sf::RenderWindow& window, sf::Color color, sf::Color txtColor, sf::Vector2f pos, std::string str) {
    //* Code to draw the speech bubble with the specified color, text color, position, and message text
    sf::RectangleShape edge(sf::Vector2f(B_HEIGHT / 5, B_HEIGHT));
    edge.setTexture(boublePtr);
    edge.setTextureRect(sf::IntRect(0, 0, 100, 500));
    edge.setFillColor(color);
    edge.setPosition(pos);
    window.draw(edge);

    sf::Text text;
    text.setFont(*fontPtr);
    text.setString(str);
    text.setCharacterSize(B_HEIGHT * 0.75);
    text.setFillColor(txtColor);
    text.setPosition(pos + sf::Vector2f(B_HEIGHT / 5 + 5, 0));

    sf::RectangleShape body(sf::Vector2f(text.getGlobalBounds().width + 20, B_HEIGHT));
    body.setFillColor(color);
    body.setPosition(pos + sf::Vector2f(B_HEIGHT / 5, 0));

    window.draw(body);
    window.draw(text);

    edge.setTextureRect(sf::IntRect(400, 0, 100, 500));
    edge.setPosition(pos + sf::Vector2f(B_HEIGHT / 5 + text.getGlobalBounds().width + 20, 0));
    window.draw(edge);
}

//* Callback function for button and editbox: Defining the function that will be called when the user presses the send button or the enter key in the edit box
void btnCallback(tgui::EditBox::Ptr eb, std::vector<Message>* msgs) {
    //* Code to handle the button press or enter key press, such as adding the message to the list of messages, clearing the edit box, and sending the message to the chatbot
    if (eb->getText() == "") return;

    std::string message = eb->getText().toStdString();  // This variable contains the message sent by the user
    eb->setText("");
    msgs->pop_back();
    msgs->push_back({message, true});

    //* To send a response base on the message, do like this
    if (message == "hello") {
        msgs->push_back({"Hello to you too", false});
    } else if (message == "how are you") {
        msgs->push_back({"Fine, thakns", false});
    } else {
        msgs->push_back({"I don't understand what you said", false});
    }
}