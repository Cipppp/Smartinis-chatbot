#include "chatbot.h"
#include "gtest/gtest.h"

TEST(ChatbotTest, TestGetResponse) {
    Chatbot cb;
    cb.addResponse("hello", "Hello, how are you?");
    cb.addResponse("goodbye", "Goodbye, have a nice day!");
    cb.addResponse("what is your name", "My name is Chatbot.");
    EXPECT_EQ(cb.getResponse("hello"), "Hello, how are you?");
    EXPECT_EQ(cb.getResponse("goodbye"), "Goodbye, have a nice day!");
    EXPECT_EQ(cb.getResponse("what is your name"), "My name is Chatbot.");
}

TEST(ChatbotTest, TestAddResponse) {
    Chatbot cb;
    cb.addResponse("hello", "Hello, how are you?");
    cb.addResponse("goodbye", "Goodbye, have a nice day!");
    cb.addResponse("what is your name", "My name is Chatbot.");
    EXPECT_EQ(cb.getResponse("hello"), "Hello, how are you?");
    EXPECT_EQ(cb.getResponse("goodbye"), "Goodbye, have a nice day!");
    EXPECT_EQ(cb.getResponse("what is your name"), "My name is Chatbot.");

    cb.addResponse("what is your purpose", "My purpose is to assist and communicate with humans.");
    EXPECT_EQ(cb.getResponse("what is your purpose"), "My purpose is to assist and communicate with humans.");
}

TEST(ChatbotTest, TestRemoveResponse) {
    Chatbot cb;
    cb.addResponse("hello", "Hello, how are you?");
    cb.addResponse("good bye", "Goodbye, have a nice day!");
    cb.addResponse("what is your name", "My name is Chatbot.");
    cb.addResponse("what is your purpose", "My purpose is to assist and communicate with humans.");
    EXPECT_EQ(cb.getResponse("hello"), "Hello, how are you?");
    EXPECT_EQ(cb.getResponse("good bye"), "Goodbye, have a nice day!");
    EXPECT_EQ(cb.getResponse("what is your name"), "My name is Chatbot.");
    EXPECT_EQ(cb.getResponse("what is your purpose"), "My purpose is to assist and communicate with humans.");

    cb.removeResponse("hello");
    cb.removeResponse("good bye");
    cb.removeResponse("what is your name");
    cb.removeResponse("what is your purpose");
    EXPECT_EQ(cb.getResponse("hello"), "I'm sorry, I don't understand what you mean.");
    EXPECT_EQ(cb.getResponse("good bye"), "I'm sorry, I don't understand what you mean.");
    EXPECT_EQ(cb.getResponse("what is your name"), "I'm sorry, I don't understand what you mean.");
    EXPECT_EQ(cb.getResponse("what is your purpose"), "I'm sorry, I don't understand what you mean.");
}
