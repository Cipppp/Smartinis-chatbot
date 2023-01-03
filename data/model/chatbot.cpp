#include "./chatbot.h"

Chatbot::Chatbot(QObject *parent) : QObject(parent)
{
}

QString Chatbot::generateResponse(const QString &message)
{
    // Generate a response based on the message
    QString response;
    if (message == "hello") {
        response = "Hello there!";
    } else if (message == "what is your name?") {
        response = "My name is Chatbot.";
    } else {
        response = "I'm sorry, I didn't understand your message.";
    }
    return response;
}
