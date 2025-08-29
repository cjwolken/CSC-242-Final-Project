#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>   // Needed for isalpha
#include <algorithm>

using namespace std;

// Function to clean a word
string cleanWord(const string& input) {
    string result;

    for (char ch : input) {
        if (isalpha(static_cast<unsigned char>(ch))) { // isalpha keeps only alphabetic characters
            result += tolower(static_cast<unsigned char>(ch));
        }
    }

    return result;
}

int main() {
    ifstream file("words.txt");
    vector<string> words;
    string word;

    if (!file) {
        cerr << "Error: could not open file.\n";
        return 1;
    }

    while (file >> word) {
        string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            words.push_back(cleaned);
        }
    }

    cout << "Words accepted into vector. " << endl;
    cout << "Comparing Input Text file..." << endl;

    ifstream inputFile("spelling.txt");
    string spellcheck;

    while (inputFile >> spellcheck) {
        if  
    }
    return 0;
}