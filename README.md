# 🔠 Auto-Suggestion System in C++

A real-time **Auto-Suggestion System** built using the **Trie Data Structure** in C++, supporting:

- ✅ Case-insensitive prefix matching  
- 📊 Frequency-based ranking (Top-K suggestions)  
- 🧠 Smart learning (adds new words when not found)  
- 📁 File persistence via `words.txt`  
- ⚙️ Beginner-friendly and efficient (DSA + File I/O project)

---

## 🚀 Features

| Feature                  | Description                                      |
|--------------------------|--------------------------------------------------|
| 🔡 Case-insensitive      | Works with both uppercase and lowercase inputs   |
| 🧠 Learns new words      | Adds user-defined words to the Trie & file       |
| 📊 Frequency Ranking     | Ranks results by usage frequency                 |
| 🔟 Top-K Results         | Displays only the most relevant K suggestions    |
| 📁 File Support          | Loads & updates words from `words.txt` file      |

---

## 📂 Project Structure
cpp-auto-suggestion-system/
├── main.cpp # Main program (user interface)
├── trie.h # Trie implementation (DSA core)
├── words.txt # Dictionary with frequency data
└── README.md # Project documentation
