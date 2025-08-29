#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std; 

int main() {
    ifstream dictionary("words.txt");  // Opens file to be used as dictionary
    if (!dictionary) {
        cerr << "Error: could not open words.txt" << endl;
        return 1;
    }

    // Define a vector of strings called words
    vector<string> words;
    string word;

    // add each word from dictionary file to the word vector
    while (dictionary >> word) {
        words.push_back(word);
    }

    // Open file to be checked
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: could not open input.txt" << endl;
        return 1;
    }

    // Print words from the input file that are not recognized
    while (inputFile >> word) {
        if (find(words.begin(), words.end(), word) == words.end()) { // This algorithm finds matching 'words' and returns to words.end
            cout << "Not found in dictionary words list: " << word << endl; // Words not found are displayed here
        }
    }

    return 0;
}

