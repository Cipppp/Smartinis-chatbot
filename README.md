# Smartinis chatbot

A chatbot class implemented in C++.

## Features

-   Pre-defined responses for certain inputs

-   Keywords for matching against user input

-   Default response for unknown inputs

-   Ability to add, remove, and update responses and keywords

-   Natural language processing capability using TensorFlow

-   Forbidden words or phrases that the chatbot should not respond to

-   Personality and mood attributes that influence responses

## Usage

To use the chatbot class, include the chatbot.h header file and create a Chatbot object.

```
#include "chatbot.h"

int main() {
    Chatbot cb;
    cb.addResponse("hello", "Hello, how are you?");
    cb.addResponse("goodbye", "Goodbye, have a nice day!");
    cb.addKeyword("what");
    cb.setDefaultResponse("I'm sorry, I don't understand what you mean.");
    cb.setPersonality("friendly");
    cb.setMood("happy");
    cout << cb.getResponse("hello") << endl;
    cout << cb.getResponse("goodbye") << endl;
    cout << cb.getResponse("what is your name?") << endl;
    return 0;
}
```

#### Output

```
Hello, how are you?
Goodbye, have a nice day!
Did you mean: what?
```

## Testing

To run the unit tests for the chatbot class, navigate to the tests directory and run make test.

## Dependencies

The chatbot class requires the following dependencies:

-   TensorFlow (for natural language processing)

-   Google Test (for unit testing)

## License

This project is licensed under the MIT License - see the LICENSE file for details.
