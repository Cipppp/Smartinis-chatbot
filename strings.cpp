#include "strings.h"

const std::string delim = "?!.;,*";

// convert a string to uppercase
void upperCase(std::string &str) {
    int len = str.length();

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';
        }
    }
}

// verifies that a given character is a punctuation
bool isPunctuation(char c) {
    return delim.find(c) != std::string::npos;
}

// removes punctuation and redundant spaces from a string
void cleanString(std::string &str) {
    // remove leading spaces
    int i = 0;
    while (i < str.length() && isspace(str[i])) {
        i++;
    }
    str = str.substr(i);

    // remove trailing spaces
    i = str.length() - 1;
    while (i >= 0 && isspace(str[i])) {
        i--;
    }
    str = str.substr(0, i + 1);

    // remove punctuation
    for (i = 0; i < str.length(); i++) {
        if (isPunctuation(str[i])) {
            str[i] = ' ';
        }
    }

    // remove redundant spaces
    i = 0;
    while (i < str.length()) {
        if (isspace(str[i])) {
            int j = i + 1;
            while (j < str.length() && isspace(str[j])) {
                j++;
            }
            if (j - i > 1) {
                str = str.substr(0, i + 1) + str.substr(j);
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
}

// copy the content of a string array to a vector
void copy(char *array[], vectorString &v) {
    for (int i = 0; i < MAX_RESP; ++i) {
        if (array[i] != NULL) {
            v.push_back(array[i]);
        } else {
            break;
        }
    }
}