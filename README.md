# Document Processing Tool

## Overview
This Document Processing Tool was developed as an assignment for the Data Structures and Algorithms course at the Indian Institute of Technology, Delhi, under Professor Subodh Vishnu Sharma. It offers advanced document processing capabilities, including storing word frequencies in a dictionary and searching for patterns within the document text.

## Technical Details

### Dictionary Storage
The dictionary storage component of the Document Processing Tool utilizes a trie-based data structure. A trie, also known as a prefix tree, is a tree-like data structure where each node represents a single character of a word. In this implementation, each node of the trie consists of a 26-element array to accommodate uppercase characters (representing the English alphabet) and a vector to handle special characters occurring at the end of words, such as punctuation marks.

- **Insertion Operation**: When inserting a word into the trie, the tool traverses the trie starting from the root node. For each character in the word, it checks if there is an existing node in the trie corresponding to that character. If not, a new node is created. This process continues until all characters of the word are inserted into the trie. Additionally, the frequency count of the word is maintained within the trie nodes, ensuring efficient retrieval and manipulation of word frequencies.
- **Retrieval Operation**: Retrieving the frequency count of a word from the trie involves traversing the trie in a manner similar to insertion. The tool follows the path corresponding to the characters of the word being searched for and returns the frequency count stored in the final node representing the last character of the word.
- **Deletion Operation**: Deleting a word from the trie involves marking the corresponding nodes as inactive or removing them from the trie structure. This operation may also involve updating the frequency counts of other words affected by the deletion.
- **Time Complexity**: The time complexity of trie operations, including insertion, deletion, and obtaining the frequency of a word, is O(k), where k is the length of the word being operated upon. This linear time complexity ensures efficient performance even for large dictionaries.

### Searching Algorithm
The searching algorithm component of the Document Processing Tool is responsible for efficiently searching for patterns within the document text. For this purpose, the tool employs the Knuth-Morris-Pratt (KMP) string search algorithm, a linear-time pattern matching algorithm known for its efficiency in searching for occurrences of a substring within a larger string.

- **Knuth-Morris-Pratt Algorithm**: The KMP algorithm operates by precomputing a prefix function that provides information about the proper shifts to be made when a mismatch occurs during the search process. This information enables the algorithm to avoid redundant comparisons and efficiently skip over portions of the text that cannot match the pattern.
- **Time Complexity**: The time complexity of the KMP algorithm is O(m + n), where m is the length of the pattern being searched for and n is the length of the document text. This linear-time complexity ensures fast and efficient pattern matching, even for large document texts.

## Usage
1. Clone the repository to your local machine.
2. Compile and run the provided source code files (`dict.cpp` and `search.cpp`) using a C++ compiler.
3. Follow the instructions provided in the assignment problem statement to perform dictionary storage and pattern searching operations using the Document Processing Tool.

## Contributions
Contributions to the project are encouraged. Fork the repository, implement enhancements or bug fixes, and submit pull requests to contribute to the ongoing development of the Document Processing Tool.
