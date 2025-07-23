#ifndef TRIE_H
#define TRIE_H

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    int frequency;

    TrieNode() {
        isEndOfWord = false;
        frequency = 0;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
    int maxResults;

    struct WordFreq {
        string word;
        int freq;

        bool operator<(const WordFreq& other) const {
            return freq < other.freq;
        }
    };

    void suggestionsRec(TrieNode* curr, string prefix, priority_queue<WordFreq>& pq) {
        if (curr->isEndOfWord) {
            pq.push({prefix, curr->frequency});
            if ((int)pq.size() > maxResults) pq.pop(); // Keep only top K
        }

        for (char c = 'a'; c <= 'z'; c++) {
            TrieNode* next = curr->children[c - 'a'];
            if (next) {
                suggestionsRec(next, prefix + c, pq);
            }
        }
    }

    string toLowercase(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

public:
    Trie(int k = 5) {
        root = new TrieNode();
        maxResults = k;
    }

    void insert(string word, int frequency = 1) {
        word = toLowercase(word);
        TrieNode* node = root;

        for (char c : word) {
            if (!isalpha(c)) continue;
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }

        node->isEndOfWord = true;
        node->frequency += frequency;
    }

    vector<string> getSuggestions(string prefix) {
        prefix = toLowercase(prefix);
        TrieNode* node = root;

        for (char c : prefix) {
            if (!isalpha(c)) continue;
            int idx = c - 'a';
            if (!node->children[idx])
                return {};
            node = node->children[idx];
        }

        priority_queue<WordFreq> pq;
        suggestionsRec(node, prefix, pq);

        vector<string> results;
        vector<WordFreq> sorted;

        while (!pq.empty()) {
            sorted.push_back(pq.top());
            pq.pop();
        }

        reverse(sorted.begin(), sorted.end());

        for (auto wf : sorted) {
            results.push_back(wf.word);
        }

        return results;
    }

    void setMaxResults(int k) {
        maxResults = k;
    }
};

#endif
