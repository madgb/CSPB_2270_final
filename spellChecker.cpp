#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    bool isWordEnd;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() : isWordEnd(false) {}
};

class SpellChecker {
private:
    TrieNode* root;

    void insertWord(const std::string &word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isWordEnd = true;
    }

    bool searchWord(const std::string &word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isWordEnd;
    }

public:
    SpellChecker() {
        root = new TrieNode();
    }

    bool loadDictionary(const std::string &file_name) {
        std::ifstream file(file_name);
        if (!file.is_open()) {
            return false;
        }

        std::string word;
        while (file >> word) {
            insertWord(word);
        }
        file.close();
        return true;
    }

    bool isSpellingCorrect(const std::string &word) {
        return searchWord(word);
    }

    std::vector<std::string> suggestWords(const std::string &wordPrefix) {
        std::vector<std::string> suggestions;
        // [Add logic to generate suggestions based on Trie traversal; this part can get quite complex.]
        return suggestions;
    }
};

// Forward Declarations
bool loadDictionary(const string& fileName, unordered_set<string>& dictionary);
bool checkSpelling(const string& word, const unordered_set<string>& dictionary);

bool loadDictionary(const string& fileName, unordered_set<string>& dictionary) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error opening dictionary file.\n";
        return false;
    }

    string word;
    while (file >> word) {
        dictionary.insert(word);
    }
    file.close();
    return true;
}

bool checkSpelling(const string& word, const unordered_set<string>& dictionary) {
    return dictionary.find(word) != dictionary.end();
}

int main() {
    unordered_set<string> dictionary;

    cout << "Welcome to the SpellChecker application.\n\n";
    cout << "This application allows you to check the spelling of words against a pre-loaded dictionary.\n";
    cout << "You can load a custom dictionary by providing the file name when prompted.\n";
    cout << "To exit the application at any time, type 'exit' or press Control+C.\n\n";

    cout << "Enter dictionary file name to load (e.g., sample_dictionary.txt): ";
    string dictionaryFileName;
    cin >> dictionaryFileName;

    // Load dictionary
    if (!loadDictionary(dictionaryFileName, dictionary)) {
        cout << "Failed to load the dictionary from " << dictionaryFileName << ". Exiting.\n";
        return 1;
    }

    string wordToCheck;
    while (true) {  // Infinite loop until "exit" is entered or Ctrl+C is pressed
        cout << "\nEnter a word to check its spelling (or type 'exit' to terminate): ";
        cin >> wordToCheck;

        if (wordToCheck == "exit") {
            cout << "Exiting the application. Goodbye!\n";
            break;
        }

        if (checkSpelling(wordToCheck, dictionary)) {
            cout << "The word '" << wordToCheck << "' is correctly spelled according to the loaded dictionary.\n";
        } else {
            cout << "The word '" << wordToCheck << "' is misspelled.\n";
        }
    }

    return 0;
}
