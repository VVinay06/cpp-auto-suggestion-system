#include <iostream>
#include <fstream>
#include <sstream>
#include "trie.h"

using namespace std;

int main() {
    int k;
    cout << "Enter number of suggestions to display (Top K): ";
    cin >> k;

    Trie trie(k);

    ifstream file("words.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        int freq;
        ss >> word >> freq;
        trie.insert(word, freq);
    }

    file.close();

    cout << "\nAuto-Suggestion System Ready!" << endl;
    cout << "Type a prefix to get suggestions (or type 'exit' to quit)\n" << endl;

    while (true) {
        cout << "Prefix: ";
        string prefix;
        cin >> prefix;

        if (prefix == "exit") break;

        vector<string> suggestions = trie.getSuggestions(prefix);

        if (suggestions.empty()) {
            cout << "No suggestions found." << endl;
            char choice;
            cout << "Do you want to add \"" << prefix << "\" to the dictionary? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                trie.insert(prefix, 1);

                // Save to file (append mode)
                ofstream outfile("words.txt", ios::app);
                outfile << prefix << " 1\n";
                outfile.close();

                cout << "Word \"" << prefix << "\" added successfully!" << endl;
            }
        } else {
            cout << "Top " << suggestions.size() << " Suggestions (by frequency):" << endl;
            for (string s : suggestions)
                cout << " - " << s << endl;
        }

        cout << endl;
    }

    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}
