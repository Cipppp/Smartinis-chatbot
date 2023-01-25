#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"

using namespace std;

// Global variables
#define B_HEIGHT 35
int WIDTH = 700;
int HEIGTH = 900;

std::string found_question;
std::string response;
std::string new_question;
std::string new_response;
int check = 0;

sf::Texture* boublePtr;
sf::Font* fontPtr;
std::unordered_map<std::string, std::string>* qaPtr;
std::vector<std::string>* swearsPtr;

struct Message {
	sf::String txt;
	bool isSent;	// true if the message has been sent by the user
};

float drawSpeechBouble(sf::RenderWindow& window, sf::Color color, sf::Color txtColor, sf::Vector2f pos, std::string str);
void btnCallback(tgui::EditBox::Ptr eb, std::vector<Message>* msgs);
void loadQA(std::string path, std::unordered_map<std::string, std::string>& qa);
void loadSwears(std::string path, std::vector<std::string>& swears);
size_t levenshtein_distance(const std::string& s1, const std::string& s2);
bool isQuestion(std::string input);
bool isNegation(std::string input);
std::string findCourse(std::string str);
std::string censorMessage(std::string message);
sf::Vector2f textFormattedSize(std::string str);

int main() {

	// Credits
	std::cout << "This application was developed by the following students from University POLITEHNICA Bucharest / Automatic Control & Computer Science Faculty within the Erasmus+ Project 2020-1-CZ01-KA226-HE-094408:" << std::endl;
	std::cout << "Pirvu Ciprian" << std::endl;
	std::cout << "Patrascu Ioana" << std::endl;
	std::cout << "Ranja Beatris" << std::endl;
	std::cout << "Antor Andrei" << std::endl;
	std::cout << "Beresteanu Alexandra" << std::endl;
	std::cout << "Cruceru Raluca" << std::endl;
	std::cout << "Militaru David" << std::endl;
	std::cout << "Minca Andrei" << std::endl;
	std::cout << "Teachers: M. Caramihai, Daniel Chis" << std::endl;


	// Load questions and answers and swear words
	std::unordered_map<std::string, std::string> qa;
	loadQA("qa.txt", qa);
	qaPtr = &qa;

	std::vector<std::string> swears;
	swearsPtr = &swears;
	loadSwears("swear.txt", swears);


	// Initialize graphics
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Smartinis-chatbot");

	// Load textures
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

	// Load font
	sf::Font font;
	if (!font.loadFromFile("Roboto-Regular.ttf")) {
		std::cout << "Error in loading font\n";
		return -1;
	}
	fontPtr = &font;

	// List of sent messages
	std::vector<Message> messages;
	messages.push_back({ "This application was developed by the following students from University POLITEHNICA Bucharest / Automatic Control & Computer Science Faculty within the Erasmus+ Project 2020-1-CZ01-KA226-HE-094408:", false });
	messages.push_back({ "Pirvu Ciprian" , false });
	messages.push_back({ "Patrascu Ioana" , false });
	messages.push_back({ "Ranja Beatris" , false });
	messages.push_back({ "Antor Andrei" , false });
	messages.push_back({ "Beresteanu Alexandra" , false });
	messages.push_back({ "Cruceru Raluca" , false });
	messages.push_back({ "Militaru David" , false });
	messages.push_back({ "Minca Andrei" , false });
	messages.push_back({ "Teachers: " , false });
	messages.push_back({ "M. Caramihai" , false });
	messages.push_back({ "Daniel Chis" , false });
	

	// GUI elements from TGUI
	tgui::Gui gui{ window };

	auto editBox = tgui::EditBox::create();
	editBox->setTextSize(0);
	editBox->setPosition(20, HEIGTH - B_HEIGHT * 2.5 + 40);
	editBox->setSize({ WIDTH - B_HEIGHT - 10 - 40, B_HEIGHT + 10 });
	editBox->setDefaultText("Write message...");
	editBox->onReturnKeyPress(&btnCallback, editBox, &messages);
	gui.add(editBox, "eb");

	tgui::Button::Ptr btn = tgui::Button::create();
	btn->setText("");
	btn->setTextSize(0);
	btn->setPosition("eb.right", "eb.top");
	btn->setSize({ B_HEIGHT + 10 , B_HEIGHT + 10 });
	btn->onPress(&btnCallback, editBox, &messages);
	gui.add(btn);

	auto toggle = tgui::ToggleButton::create("");
	toggle->setTextSize(0);
	toggle->setSize({ B_HEIGHT * 2 , B_HEIGHT * 2 });
	toggle->setPosition(WIDTH - B_HEIGHT*2 - 40, HEIGTH / 7 / 2 - B_HEIGHT);
	gui.add(toggle);

	// Current color scheeme
	sf::Color background = sf::Color(0xf5f5f5ff);
	sf::Color banners = sf::Color::White;
	sf::Color moonColor = sf::Color(0x111111ff);

	// Misc variables
	float screenPos = HEIGTH-150.;
	sf::Text textMesure;
	sf::Text textShortMeasure;
	textMesure.setCharacterSize(B_HEIGHT * 0.75);
	textMesure.setFont(font);
	textShortMeasure.setString("abcdefghijklmnopqrstuvwxyzabc");
	textShortMeasure.setCharacterSize(B_HEIGHT * 0.75);
	textShortMeasure.setFont(font);
	int animPos = 0;
	bool mouseOverMoon = false;

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
					screenPos = std::max(screenPos + event.mouseWheelScroll.delta * 10, HEIGTH-150.f);
				break;

			case sf::Event::MouseMoved:
				mouseOverMoon = toggle->isMouseOnWidget(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
				break;

			case sf::Event::Resized:
				WIDTH = event.size.width;
				HEIGTH = event.size.height;
				window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

				editBox->setPosition(20, HEIGTH - B_HEIGHT * 2.5 + 40);
				editBox->setSize({ WIDTH - B_HEIGHT - 10 - 40, B_HEIGHT + 10 });

				btn->setPosition("eb.right", "eb.top");
				btn->setSize({ B_HEIGHT + 10 , B_HEIGHT + 10 });

				toggle->setSize({ B_HEIGHT * 2 , B_HEIGHT * 2 });
				toggle->setPosition(WIDTH - B_HEIGHT * 2 - 40, HEIGTH / 7 / 2 - B_HEIGHT);
				break;
			}

			gui.handleEvent(event);
		}

		// Dark mode logic
		if (toggle->isDown()) {
			background = sf::Color(0x333333ff);
			banners = sf::Color(0x111111ff);
			moonColor = (mouseOverMoon) ? sf::Color(0xddddddff) : sf::Color::White;
		} else {
			background = sf::Color(0xf5f5f5ff);
			banners = sf::Color::White;
			moonColor = (mouseOverMoon) ? sf::Color(0x333333ff) : sf::Color(0x111111ff);
		}

		// Dot animation logic
		if (editBox->getText() != "" && messages[messages.size() - 1].txt != "          ") {
			messages.push_back({ "          ", true });
		} else if(editBox->getText() == "" && messages[messages.size() - 1].txt == "          ") {
			messages.pop_back();
		}

		// Draw
		window.clear(background);

		// Draw speech boubles
		float screenPosRelative = screenPos;
		for (int i = messages.size() - 1; i >= 0; i--) {
			if (messages[i].isSent) {
				textMesure.setString(messages[i].txt);
				screenPosRelative -= drawSpeechBouble(
					window,
					sf::Color(0x3888ebff),								// Background color
					sf::Color(0xffffffff),						// Text color
					sf::Vector2f(
						WIDTH - 40 - textFormattedSize(messages[i].txt).x - B_HEIGHT / 5 * 2,
						screenPosRelative - textFormattedSize(messages[i].txt).y
					),													// Position
					messages[i].txt									// Text
				);
			} else {
				screenPosRelative -= drawSpeechBouble(
					window,
					sf::Color(0xe4e4e4ff),								// Background color
					sf::Color(0x000000ff),						// Text color
					sf::Vector2f(20, screenPosRelative - textFormattedSize(messages[i].txt).y),	// Position
					messages[i].txt									// Text
				);
			}
			screenPosRelative -= 10;
		}

		// Draw dots
		if (editBox->getText() != "") {
			sf::Vector2f boublePos(WIDTH - B_HEIGHT*3 + 25, screenPos - B_HEIGHT/2 -5);
			for (int i = 0; i < 3; i++) {
				sf::CircleShape dot(10);
				dot.setFillColor(sf::Color::White);
				dot.setPosition(sf::Vector2f(
					i * 30,
					(animPos + i < 50) ? (- sin((animPos + i * 5) * 3.6 * 3.14 / 180) * B_HEIGHT / 4)
					: 0)
				+ boublePos);
				window.draw(dot);
				animPos++;
				if (animPos == 200) animPos = 0;
			}
		}

		// Draw GUI
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

		while (timer.getElapsedTime().asMilliseconds() < 1000 / 60);
		timer.restart();
	}

	return 0;
}

float drawSpeechBouble(sf::RenderWindow& window, sf::Color color, sf::Color txtColor, sf::Vector2f pos, std::string str) {
	sf::RectangleShape edge(sf::Vector2f(B_HEIGHT / 5, B_HEIGHT));
	edge.setTexture(boublePtr);
	edge.setTextureRect(sf::IntRect(0, 0, 100, 500));
	edge.setFillColor(color);
	edge.setPosition(pos);

	sf::Text text;
	text.setFont(*fontPtr);
	text.setString(str);
	text.setCharacterSize(B_HEIGHT * 0.75);
	text.setFillColor(txtColor);
	text.setPosition(pos + sf::Vector2f(B_HEIGHT / 5 + 5, 0));

	sf::RectangleShape body(sf::Vector2f(text.getGlobalBounds().width + 20, B_HEIGHT));
	body.setFillColor(color);
	body.setPosition(pos + sf::Vector2f(B_HEIGHT / 5, 0));

	int newLineCount = 1;
	while (text.getLocalBounds().width >= WIDTH - 20) {
		if (str.size() - 1 > newLineCount * 30)
			str.insert(str.begin() + newLineCount * 30, '\n');
		else {
			newLineCount--;
			break;
		}
		newLineCount++;
		text.setString(str);
	}
	body.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, B_HEIGHT * newLineCount));
	edge.setSize(sf::Vector2f(B_HEIGHT / 5, B_HEIGHT * newLineCount));

	window.draw(body);
	window.draw(text);
	window.draw(edge);

	edge.setTextureRect(sf::IntRect(400, 0, 100, 500));
	edge.setPosition(pos + sf::Vector2f(B_HEIGHT / 5 + text.getGlobalBounds().width + 20, 0));
	window.draw(edge);

	return newLineCount * B_HEIGHT;
}

// This function gets called when the button is pressed
void btnCallback(tgui::EditBox::Ptr eb, std::vector<Message>* msgs) {
	if (eb->getText() == "") return;

	std::string message = eb->getText().toStdString() + " ";		// This variable contains the message sent by the user
	std::string msgClear = eb->getText().toStdString();
	// Remove swear words											
	message = censorMessage(message);

	eb->setText("");
	msgs->pop_back();
	msgs->push_back({ message, true});

	message = msgClear;
	//std::transform(message.begin(), message.end(), message.begin(), [](unsigned char c) { return std::tolower(c); });
	
	// To send a response base on the message, do like this
	std::unordered_map<std::string, std::string>::iterator it = (*qaPtr).begin(); // iterates through the map questions

	if (check == 0) {
		// Finds the most similar question to the input
		int total = levenshtein_distance(message, it->first); 
		while (it != (*qaPtr).end()) {
			int tempTotal = levenshtein_distance(message, it->first);
			// - count keywords
			if (tempTotal <= total) {
				total = tempTotal;
				found_question = it->first;
				response = it->second;
			}
			++it;
		}
		// If the found question is close enough to the input...
		if (total <= message.size()/2 + 8/2) {
			// ... checks if Smartini forgot the answer (check becomes 2)
			int chance = rand() % 100;
			if ((chance == 1) && (found_question != "hello")) {
				msgs->push_back({ "I think I forgot the answer. Can you remind me ?", false });
				check = 2;
			}
			// If he remembers, he shows the answer as well as the course he found the answer in, in case it's in a course
			else {
				string course = findCourse(found_question);
				if (course != "")
					msgs->push_back({ course, false });
				msgs->push_back({ response, false });
			}
		}
		// If it's not, Smartini asks for the answer if the input is indeed a question (check becomes 1)
		else {
			msgs->push_back({ "I don't understand what you said", false });
			if (isQuestion(message)) {
				msgs->push_back({ "Do you know " + message, false });
				new_question = message;
				check = 1;
			}
		}
	}
	// Case where Smartini already asked for the answer
	else if (check == 1) {
		// If the input is an affirmation (and, possibly, the answer)...
		if (!isNegation(message)) {
			// ... he memorizes the new info received.
			msgs->push_back({ "Thank you for the answer!", false });
			new_response = message;
			(*qaPtr).insert({ new_question, new_response });

			std::fstream existent_file, new_file;
			std::string line;

			existent_file.open("qa.txt", std::ios::in);
			new_file.open("newqa.txt", std::ios::out);

			while (existent_file) {
				getline(existent_file, line);
				if (existent_file.eof())
					break;
				new_file << line << "\n";
				if (line == "###QUESTIONS###") {
					new_file << new_question << "\n";
				}
				if (line == "###ANSWERS###") {
					new_file << new_response << "\n";
				}

			}
			existent_file.close();
			new_file.close();
			//std::remove("qa.txt");
			//std::rename("newqa.txt", "qa.txt");
			check = 0;
		}
		// If the input is a negation (the user doesn't know either), Smartini sighs in disappointment...
		else {
			msgs->push_back({ "Ok.", false });
			check = 0;
		}
	}
	// Case where Smartini forgot the answer
	else if (check == 2) {
		int distance = levenshtein_distance(message, response);
		// If the answer received is close enough to the actual answer...
		if (!isNegation(message)) {
			if (distance <= message.size() / 2) {
				// ... Smartini thanks the user!
				msgs->push_back({ "Yes, that's it! Thank you for reminding me!", false });
				msgs->push_back({ "What else do you want to find out?", false });
				check = 0;
			}
			// If not, he disapproves and continues the discussion
			else {
				msgs->push_back({ "I don't think that's the answer, actually.", false });
				msgs->push_back({ "What else do you want to find out?", false });
				check = 0;
			}
		}
		// If the input is a negation (the user doesn't remember either), Smartini sighs in disappointment...
		else {
			msgs->push_back({ "Ok.", false });
		}
	}
	
}

void loadQA(std::string path, std::unordered_map<std::string, std::string>& qa) {
	std::fstream newfile;
	newfile.open(path, std::ios::in);
	std::vector<std::string> questions;
	std::vector<std::string> answers;

	if (newfile.is_open()) {
		std::string tp;
		bool qOrA = true;
		while (getline(newfile, tp)) {
			if (tp == "###QUESTIONS###")
				continue;

			if (tp == "###ANSWERS###") {
				qOrA = false;
				continue;
			}

			if (qOrA) {
				questions.push_back(tp);
			} else {
				answers.push_back(tp);
			}
		}

		for (int i = 0; i < questions.size(); i++) {
			qa[questions[i]] = answers[i];
		}

		newfile.close();
	}
}

void loadSwears(std::string path, std::vector<std::string>& swears) {
	std::fstream newfile;
	newfile.open(path, std::ios::in);

	if (newfile.is_open()) {
		std::string tp;
		while (getline(newfile, tp)) {
			swears.push_back(tp);
		}
		newfile.close();
	}
}

sf::Vector2f textFormattedSize(std::string str) {
	sf::Text text;
	text.setFont(*fontPtr);
	text.setString(str);
	text.setCharacterSize(B_HEIGHT * 0.75);

	int newLineCount = 1;
	while (text.getLocalBounds().width >= WIDTH - 20) {
		if (str.size() - 1 > newLineCount * 30)
			str.insert(str.begin() + newLineCount * 30, '\n');
		else {
			newLineCount--;
			break;
		}
		newLineCount++;
		text.setString(str);
	}
	return sf::Vector2f(text.getGlobalBounds().width, newLineCount * B_HEIGHT);
}

// Functions that the Chatbot uses

size_t levenshtein_distance(const string& s1, const string& s2) {
	const size_t m(s1.size());
	const size_t n(s2.size());

	if (m == 0) return n;
	if (n == 0) return m;

	size_t* costs = new size_t[n + 1];

	for (size_t k = 0; k <= n; k++) costs[k] = k;

	size_t i = 0;
	for (string::const_iterator it1 = s1.begin(); it1 != s1.end(); ++it1, ++i) {
		costs[0] = i + 1;
		size_t corner = i;

		size_t j = 0;
		for (string::const_iterator it2 = s2.begin(); it2 != s2.end(); ++it2, ++j) {
			size_t upper = costs[j + 1];
			if (*it1 == *it2) {
				costs[j + 1] = corner;
			}
			else {
				size_t t(upper < corner ? upper : corner);
				costs[j + 1] = (costs[j] < t ? costs[j] : t) + 1;
			}

			corner = upper;
		}
	}

	size_t result = costs[n];
	delete[] costs;

	return result;
}

bool isQuestion(std::string input) {
	if (input.find("?") != string::npos)
		return true;
	else
		return false;
}

bool isNegation(std::string input) {
	string word;
	vector<string> row;

	stringstream s(input);

	while (getline(s, word, ' ')) {
		row.push_back(word);
	}
	for (auto it = row.begin(); it != row.end(); it++) {
		string tester = *it;
		if ((tester == "no") || (tester == "not") || (tester == "No") || (tester.find("n't") != string::npos))
			return true;
	}
	return false;
}

std::string findCourse(string str) {
	string result = "";
	if (str.find("COURSE1") != string::npos)
		result = "I've found this in Course 1";
	if (str.find("COURSE2") != string::npos)
		result = "I've found this in Course 2";
	if (str.find("COURSE3") != string::npos)
		result = "I've found this in Course 3";
	if (str.find("COURSE4") != string::npos)
		result = "I've found this in Course 4";
	if (str.find("COURSE5") != string::npos)
		result = "I've found this in Course 5";
	if (str.find("COURSE6") != string::npos)
		result = "I've found this in Course 6";
	if (str.find("COURSE7") != string::npos)
		result = "I've found this in Course 7";
	if (str.find("COURSE8") != string::npos)
		result = "I've found this in Course 8";
	if (str.find("COURSE9") != string::npos)
		result = "I've found this in Course 9";
	if (str.find("COURSEX") != string::npos)
		result = "I've found this in Course 10";
	if (str.find("COURSEY") != string::npos)
		result = "I've found this in Course 11";
	if (str.find("COURSEZ") != string::npos)
		result = "I've found this in Course 12";

	return result;
}

std::string censorMessage(std::string message) {
	vector<string> words;
	string word;
	string result = "";
	std::stringstream s(message);

	while(getline(s, word, ' '))
		words.push_back(word);

	for (int i = 0; i < swearsPtr->size(); i++) {
		for (auto it = words.begin(); it != words.end(); it++) {
			if (*it == (*swearsPtr)[i]) {
				int word_size = (*it).size();
				for (int j = 0; j < word_size; j++)
					(*it)[j] = '*';
			}
		}
	}
	for (auto it = words.begin(); it != words.end(); it++) {
		result = result + *it + " ";
	}
	return result;
}

// Possible future implementations:
/*
	- eSpeak???
	+ modified global variable text dimensions
	+ fix the swear words (don't use the string::find function, otherwise "hello" that contains "hell" will be censored)
	- encrypt swear words
	- add popping bubbles while Smartini writes, put 1 second delay before sending the answer
	- check why certain words become split in the popped message in GUI
	+ translate questions and append the course to every one of them "-COURSEX"
	+ show the course ("I've found this in course x" in case the levenshtein distance is short enough)
	- select some keywords as well as synonimes for each question, then substract from the total levenshtein distance a certain 
	  value if a keyword has been found (also for questions 3 and 22, if i give a synonim for question 3 i get the 22th answer)
	  When doing so, levenshtein distance should be q_length/2 +8 - (length of keywords found)
	- write in documentation about Levenshtein distance (NLP method)
	- fix file problem
	- course 3 answers are not in the question order and that's fucked-up.
*/
