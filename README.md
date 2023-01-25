# **Smartinis Chatbot**

## **Features**

-   User can interact with the chatbot through a GUI
-   Swear words are automatically replaced with asterisks (\*)
-   The chatbot is able to respond to user input based on a predefined set of questions and answers
-   The application features a night mode

## **Getting Started**

### **Prerequisites**

-   c++11 or later
-   SFML library
-   TGUI library

### **Installation**

**1. Clone the repository**

    `git clone https://github.com/smartinis/chatbot.git`

**2. Compile the code**

```
cd chatbot
```

**3. Run the application:**

```
./chatbot
```

## **Overview**

The Smartinis Chatbot is a chatbot application that uses a pre-defined set of questions and answers to respond to user input. It also includes a feature to censor swear words in the user's input. The application is built using C++ with the SFML and TGUI libraries for graphics and GUI elements.

## **Functionality**

The following functionality is provided by the Smartinis Chatbot:

-   The chatbot loads a set of pre-defined questions and answers from a text file (qa.txt) and stores them in a std::unordered_map. The key for each entry is the question in lowercase, and the value is the corresponding answer.
-   The chatbot also loads a set of swear words from a text file (swear.txt) and stores them in a std::vector.
-   When the user types in a message and presses the send button or the return key, the message is checked for swear words using the std::find() function and any swear words found are replaced with asterisks (\*). The modified message is then added to the list of messages sent by the user.
-   The chatbot then looks up the user's message in the std::unordered_map of pre-defined questions and answers. If a match is found, the corresponding answer is added to the list of messages sent by the chatbot. If no match is found, the chatbot sends the message "I don't understand what you said".
-   The chatbot also includes a feature to change the color scheme of the application by clicking on the moon icon 
-   The chatbot is able to find an appropiate match to the user input, thus providing the respective answer.

## **GUI Elements**

The following GUI elements are used in the Smartinis Chatbot:

-   **Edit box**: This is used to enter the user's message. It is positioned at the bottom of the window and takes up most of the width.

-   **Button**: This is used to send the message entered in the edit box. It is positioned to the right of the edit box.

-   **Toggle button**: This is used to change the color scheme of the application. It is positioned on the top right of the window

## **Dependencies**

The Smartinis Chatbot depends on the following libraries:

-   SFML (Simple and Fast Multimedia Library)
-   TGUI (GUI library for SFML)

## **Usage**

The program will open a window with a chatbot interface. The user can input a message in the text box at the bottom of the screen and press enter or the send button to send the message. The chatbot will then respond with a pre-defined answer if it understands the message, or a default "I don't understand what you said" if it does not.

The program also has a feature that filters out swear words and replaces them with asterisks in the user's message before displaying it. The list of swear words is stored in a file called "swear.txt".

The pre-defined questions and answers are stored in a file called "qa.txt", which should be in the same format as the example file provided in the repository. Each question and answer should be on a separate line, with the question and answer separated by a comma.

## **How to use**

-   Install the SFML and TGUI libraries
-   Clone or download the repository
-   Build and run the project
-   Type a message in the edit box and press the send button or the return key to send the message
-   Click on the moon icon to change the color scheme
-   To update the pre-defined questions and answers, update the qa.txt file
-   To update the swear words, update the swear.txt file

### **Night mode**

The application features a night mode that can be activated by clicking the moon icon in the top right corner of the window. The night mode changes the color scheme of the application to a darker theme, making it easier on the eyes in low-light environments.

### **Swear words**

The application automatically replaces swear words with asterisks (\*) in the messages sent by the user. The list of swear words is defined in the swear.txt file.

### **Questions and answers**

The chatbot's responses are based on a predefined set of questions and answers. The questions and answers are defined in the qa.txt file in the format question:answer. The questions are case-insensitive.

## **Customization**

The following elements of the application can be customized:

-   The list of swear words
-   The questions and answers that the chatbot - is able to respond to
-   The width and height of the window
-   The color scheme of the application

## **Drawbacks**

-   The program only replaces swear words, it does not detect other types of offensive language.
-   The program does not have any kind of memory or context, so it will not be able to carry on a conversation.
-   The program does not have any kind of natural language processing, so it will not be able to understand complex sentences or idioms.

## **Limitations**

-   The Smartinis Chatbot is only able to respond to pre-defined questions and does not have the ability to understand natural language input.
-   The Smartinis Chatbot does not have a database to store the previous messages.
-   The Smartinis Chatbot does not have the ability to change the background image
-   The Smartinis Chatbot does not have the ability to change the font

## **How to use Smartini**

-   Every message input should be written in lowercase characters, otherwise Smartini will not understand the message
-   If the user wants to ask Smartini a question, the input must have the "?" character at the end of it

## **Conclusion**

The Smartinis Chatbot is a simple chatbot application that demonstrates the basics of how a chatbot works. It can be used as a starting point for building more advanced chatbots with natural language processing capabilities.

## **Authors**

Smartinis - Smartinis

## **Folder source**

In order to get the entire application library, do access this link: 
https://we.tl/t-P0nAT1mWxq. If not, replace the main file from the posted archive with the main file posted separately.
