#include <ctime>
#include <iostream>

#include "strings.h"

using namespace std;

typedef struct {
    char *keyword;
    char *response[MAX_RESP];
} record;

class Chatbot {
   public:
    Chatbot();
    ~Chatbot();

    void getInput();
    void respond();

    bool isQuit() const {
        return quitProgram;
    }

   private:
    void findMatch();
    void handleRepetition();
    void handleUserRepetition();
    void handleEvent(string event);

    // random number generator seed
    void seedRandomGenerator() {
        srand(time(0));
    }

    // select a response using shuffle function
    void selectResponse() {
        suffleArray(responseList, responseList.size());
        response = responseList[0];
    }

    // save previous input
    void savePreviousInput() {
        prevInput = userInput;
    }

    // save previous response
    void savePreviousResponse() {
        prevResponse = response;
    }

    // save previous event
    void savePreviousEvent() {
        prevEvent = event;
    }

    // set event to argument
    void setEvent(string event) {
        this->event = event;
    }

    // save input to backup
    void saveInputBackup() {
        inputBackup = userInput;
    }

    // set input
    void setInput(string input) {
        userInput = input;
    }

    // restore input from backup
    void restoreInput() {
        userInput = inputBackup;
    }

    // print response if not empty
    void printResponse() {
        if (!response.empty()) {
            cout << chatbotName << ": " << response << endl;
        }
    }

    // preprocess input
    void preprocessInput() {
        cleanString(userInput);
        upperCase(userInput);
    }

    // return chatbot repeat if response is same as previous response and not empty
    bool isChatbotRepeat() const {
        return response == prevResponse && !response.empty();
    }

    // return user repeat if input is same or similar to previous input and not empty
    bool isUserRepeat() const {
        return userInput == prevInput || userInput.find(prevInput) != string::npos || prevInput.find(userInput) != string::npos && !userInput.empty();
    }

    // return boolean if chatbot understands input
    bool isUnderstood() const {
        return !response.empty();
    }

    // return boolean for null input or previous input
    bool isNullInput() const {
        return userInput.empty() || prevInput.empty();
    }

    // return boolean if users wants to quit
    bool userQuits() const {
        // if you find the word (make it lowercase) quit in the input string return true
        return userInput.find("QUIT") != string::npos;
    }

    // return boolean if same event and is not empty event
    bool isSameEvent() const {
        return event == prevEvent && !event.empty();
    }

    // return boolean if there is no response
    bool isNoResponse() const {
        return response.empty();
    }

    // Check if input is the same
    bool isSameInput() const {
        return userInput == prevInput;
    }

    // return boolean if input is not empty and there are similar inputs
    bool isSimilarInput() const {
        return !userInput.empty() && (userInput.find(prevInput) != string::npos || prevInput.find(userInput) != string::npos);
    }

   private:
    string chatbotName;
    string userName;
    string userInput;
    string response;
    string prevInput;
    string prevResponse;
    string event;
    string prevEvent;
    string inputBackup;
    bool quitProgram;
    vectorString responseList;
};