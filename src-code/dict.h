// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Dict
{
private:
    struct TrieNode
    {
        int count;
        TrieNode *children[26];

        TrieNode()
        {
            count = 0;
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }

        ~TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                if (children[i])
                {
                    delete children[i];
                    children[i] = nullptr;
                }
            }
        }

        bool isFilled(char c)
        {
            if (children[c - 'a'])
                return true;
            return false;
        }

        void fill(char c)
        {
            if (!children[c - 'a'])
            {
                TrieNode *temp = new TrieNode();
                children[c - 'a'] = temp;
            }
        }

        bool isEnd()
        {
            return count > 0;
        }

        void setEnd()
        {
            count++;
        }

        int getCount()
        {
            return count;
        }
    };

    struct Trie
    {
        TrieNode *root;

        Trie()
        {
            root = new TrieNode();
        }

        ~Trie()
        {
            delete root;
        }

        void insertTrie(const string &word)
        {
            TrieNode *curr = root;
            for (char c : word)
            {
                curr->fill(c);
                curr = curr->children[c - 'a'];
            }
            curr->setEnd();
        }

        bool searchTrie(const string &word)
        {
            TrieNode *curr = root;
            for (char c : word)
            {

                if (!curr->isFilled(c))
                {
                    return false; // Word not found
                }
                curr = curr->children[c - 'a'];
            }
            return curr->isEnd();
        }

        int getWordCount(const string &word)
        {
            TrieNode *curr = root;
            for (char c : word)
            {

                if (!curr->isFilled(c))
                {
                    return 0;
                }
                curr = curr->children[c - 'a'];
            }
            return curr->getCount();
        }

        TrieNode *getRoot()
        {
            return root;
        }
    };

    Trie *store;
    static void dumpTrie(TrieNode *node, string word, ofstream &outFile);

public:
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};