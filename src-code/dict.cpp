// Do NOT add any other includes
#include "dict.h"

vector<string> splitAndNormalize(string &input)
{
    vector<string> result;
    
    string word = "";

    for (char c : input)    
    {
        // c='”' ||c=='“' || c=='‘' || c=='’' || c=='—' || c=='˙'
        if (c == ',' || c=='.' || c == '-' || c==':' || c=='!' || c == '(' || c == ')' || c == '?'  || c == '[' || c == ']'  || c == '"' || c == '\'' || c == '`' || c == ';' || c == '@' || c == ' ')
        {
            if (!word.empty())
            {
                result.push_back(word);
                word = "";
            }
        }
        else
        {
            // Convert uppercase to lowercase
            word += tolower(c);
        }
    }

    // Add the last word if it's not empty
    if (!word.empty())
    {
        result.push_back(word);
    }

    return result;
}

void Dict::dumpTrie(TrieNode *node, string word, ofstream &outFile)
{
    if (node->getCount() > 0)
    {
        outFile << word << ", " << node->getCount() << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i])
        {
            char c = 'a' + i;
            dumpTrie(node->children[i], word + c, outFile);
        }
    }
}

Dict::Dict()
{
    store = new Trie();
}

Dict::~Dict()
{
    delete store;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    vector<string> words;
    words = splitAndNormalize(sentence);
    
    for (const string &word : words)
    {
        // Insert the word into the Trie
        store->insertTrie(word);
    }
}

int Dict::get_word_count(string word)
{
    return store->getWordCount(word);
}

void Dict::dump_dictionary(string filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        string s = "";
        dumpTrie(store->getRoot(), s, outFile);
        outFile.close();
    }
    else
    {
        cerr << "Error: Unable to open the file for writing." << endl;
    }
}

// int main()
// {
//     // Create an instance of the Dict class
//     Dict* dict=new Dict();

//     // Insert test sentences
//     dict->insert_sentence(1, 1, 1, 1, "Suck on my test@hello;,cases'");
//     dict->insert_sentence(1, 1, 1, 2, "Another test nibba balls nibba nibb  sentence for testing.");
//     dict->insert_sentence(2, 2, 2, 1, "Hello, world!nib.nibber?nibba");

//     // Test case 1: Get word count
//     cout << "Word count for 'test': " << dict->get_word_count("test") << endl;
//     cout << "Word count for 'nibba': " << dict->get_word_count("nibba") << endl;
//     cout << "Word count for 'nibb': " << dict->get_word_count("nibb") << endl;

//     // Test case 2: Dump dictionary
//     dict->dump_dictionary("dictionary.txt");
//     cout << "Dictionary dumped to 'dictionary.txt'." << endl;
//     delete dict;
//     return 0;
// }