## Project: Real-time Spell Check using Trie-HashMap Hybrid Structure
**Name:** [Woobin Huh]
**Class and Semester:** CSBP-2270, Fall 2023

In modern text processing systems, real-time spell check is an indispensable feature. Whether it's in word processors, chat applications, or code editors, instant feedback on spelling helps users communicate more effectively and confidently. The challenge lies in efficiently querying a vast dictionary of words to identify spelling errors without introducing noticeable lags.

In the course, we've explored Hash Maps and Tries as independent data structures. While Hash Maps offer quick lookups for known keys, they aren't ideal for querying prefixes or possible permutations. On the other hand, Tries, though well-suited for prefix queries, can be memory intensive. A fusion of these data structures, a Trie-HashMap hybrid, can harness their strengths, providing both space and time efficiency.

This Trie-HashMap hybrid will be encapsulated in a `SpellChecker` class. Here's a tentative breakdown:

**Data Structures:**
- `TrieNode`: A node in the trie. Each node represents a character and contains a HashMap of child nodes, speeding up the child lookup process.
- `HashMap`: A standard hash map to store child nodes within the TrieNode.

**Public Member Functions:**
- `bool loadDictionary(string file_name)`: Loads a dictionary file into the Trie-HashMap hybrid. Returns true if successful.
- `vector<string> suggestWords(string word)`: Given an input word, this function returns possible correct spellings.
- `bool isSpellingCorrect(string word)`: Checks if a word is correctly spelled according to the loaded dictionary.

**Private Member Functions:**
- `void insertWord(string word)`: Inserts a word into the Trie-HashMap structure.
- `bool searchWord(string word)`: Searches for a word in the Trie-HashMap.

For testing the `SpellChecker`:

**Testing Criteria:**
- **Test Case 1**: Load a dictionary file and verify successful loading.
- **Test Case 2**: Query known misspellings and ensure the `isSpellingCorrect` function returns `false`.
- **Test Case 3**: For known misspellings, check that `suggestWords` returns relevant suggestions.
- **Test Case 4**: Use the spell checker in a mock text editor setting, simulating real-time spelling checks. Performance will be measured by the time taken to process inputs.

Through this project, I aim to demonstrate that a Trie-HashMap hybrid can effectively bridge the gap between the advantages of Tries and Hash Maps, offering an efficient solution for real-time spell checking applications.

**References:**  
[1] Textbook: Data Structures and Algorithm Analysis  
[2] https://en.wikipedia.org/wiki/Trie  
[3] https://www.geeksforgeeks.org/trie-insert-and-search/ (For Trie-based concepts, no code used)  
[4] https://en.wikipedia.org/wiki/Hash_table  
