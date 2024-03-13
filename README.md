# Document Processing Tool

## Overview
This Document Processing Tool was developed as an assignment for the Data Structures and Algorithms course (COL106) at the Indian Institute of Technology, Delhi, under the guidance of Professor Subodh Vishnu Sharma. It offers advanced document processing capabilities, including storing word frequencies in a dictionary and searching for patterns within the document text.

## Technical Details

### Dictionary Storage
The dictionary storage component of the Document Processing Tool utilizes a trie-based data structure. A trie, also known as a prefix tree, is a tree-like data structure where each node represents a single character of a word. In this implementation, each node of the trie consists of a 26-element array to accommodate lowercase characters (representing the English alphabet, converted to lowercase if they are uppercase) and a vector to handle numbers and special characters.

- **Insertion Operation**: When inserting a word into the trie, the tool traverses the trie starting from the root node. For each character in the word, it checks if there is an existing node in the trie corresponding to that character. If not, a new node is created. This process continues until all characters of the word are inserted into the trie. Additionally, the frequency count of the word is maintained within the trie nodes, ensuring efficient retrieval and manipulation of word frequencies.
- **Retrieval Operation**: Retrieving the frequency count of a word from the trie involves traversing the trie in a manner similar to insertion. The tool follows the path corresponding to the characters of the word being searched for and returns the frequency count stored in the final node representing the last character of the word.
- **Deletion Operation**: Deleting a word from the trie involves marking the corresponding nodes as inactive or removing them from the trie structure. This operation may also involve updating the frequency counts of other words affected by the deletion.
- **Dumping Feature**: The tool provides a feature to dump the dictionary into a file. Each word in the dictionary is written to the file along with its frequency count, allowing for easy inspection and analysis of the word frequencies.
- **Time Complexity**: The time complexity of trie operations, including insertion, deletion, and obtaining the frequency of a word, is O(k), where k is the length of the word being operated upon. This linear time complexity ensures efficient performance even for large dictionaries.

### Searching Algorithm
The searching algorithm component of the Document Processing Tool involves iterating through each sentence of each page of each book, stored as a string (converted to lowercase) in a string vector. To search for a specific word/pattern, the pattern is first converted to lowercase (with uppercase characters converted, and lowercase/special characters retained). Then, the vector is iterated, and on each sentence, the Knuth-Morris-Pratt (KMP) algorithm is applied to search for the pattern. If the pattern is found, details of that sentence, including the start character, page number, and book, are stored in a node. This process is repeated for all sentences.

## Usage
1. Clone the repository to your local machine.
2. Compile and run the provided source code files (`dict.cpp` and `search.cpp`) using a C++ compiler.
3. Follow the instructions provided in the assignment problem statement to perform dictionary storage, pattern searching operations, and dictionary dumping using the Document Processing Tool.

## Contributions
Contributions to the project are encouraged. Fork the repository, implement enhancements or bug fixes, and submit pull requests to contribute to the ongoing development of the Document Processing Tool.
