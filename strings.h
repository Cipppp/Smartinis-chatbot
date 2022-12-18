#ifndef __STRING_H__
#define __STRING_H__

// pragma to disable warning for strcpy
#pragma warning(disable : 4786)
#include <string>
#include <vector>

using namespace std;

const int MAX_RESP = 4;

typedef vector<string> vectorString;

bool isPunctuation(char c);
void cleanString(string &str);
void upperCase(string &str);
void copy(char *array[], vectorString &v);

template <typename T>
void suffleArray(T &array, size_t size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        swap(array[i], array[j]);
    }
}

#endif