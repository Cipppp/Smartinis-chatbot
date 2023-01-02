// Create a chatbot class
// Constructor
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Chatbot
{
public:
    Chatbot();
    ~Chatbot();
    void loadPhrases();
    string getPhrase();
    string getPhrase(int index);
    int getNumberOfPhrases();
    void addPhrase(string phrase);
    void removePhrase(int index);
    void savePhrases();
    void printPhrases();
    vector<string> phrases;
};
    

Chatbot::Chatbot()
{
    srand(time(0)); // seed the random number generator
    loadPhrases();
}

// Destructor
Chatbot::~Chatbot()
{
}

// Load phrases from a file
void Chatbot::loadPhrases()
{
    // Open the file
    ifstream file;
    file.open("phrases.txt");

    // Read the file line by line
    string line;
    while (getline(file, line))
    {
        phrases.push_back(line);
    }

    // Close the file
    file.close();
}

// Get a phrase from the list
string Chatbot::getPhrase()
{
    // Get a random number between 0 and the size of the vector
    int index = rand() % phrases.size();

    // Print the phrase at the random index
    return phrases[index];
}

// Get a phrase from the list
string Chatbot::getPhrase(int index)
{
    // Check the index is valid
    if (index >= 0 && index < phrases.size())
    {
        // Return the phrase at the index
        return phrases[index];
    }

    // Return an empty string
    return "";
}

// Get the number of phrases
int Chatbot::getNumberOfPhrases()
{
    return phrases.size();
}

// Add a phrase to the list
void Chatbot::addPhrase(string phrase)
{
    phrases.push_back(phrase);
}

// Remove a phrase from the list
void Chatbot::removePhrase(int index)
{
    // Check the index is valid
    if (index >= 0 && index < phrases.size())
    {
        // Remove the phrase at the index
        phrases.erase(phrases.begin() + index);
    }
}

// Save phrases to a file
void Chatbot::savePhrases()
{
    // Open the file
    ofstream file;
    file.open("phrases.txt");

    // Write the phrases to the file
    for (string phrase : phrases)
    {
        file << phrase << endl;
    }

    // Close the file
    file.close();
}

// Print the phrases to the console
void Chatbot::printPhrases()
{
    // Print the phrases to the console
    for (string phrase : phrases)
    {
        cout << phrase << endl;
    }
}


