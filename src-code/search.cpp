

// Do NOT add any other includes
#include "search.h"

SearchEngine::SearchEngine()
{
    // Implement your function here
}

SearchEngine::~SearchEngine()
{
    // Implement your function here
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    SentenceEntry entry;
    entry.book_code = book_code;
    entry.page = page;
    entry.paragraph = paragraph;
    entry.sentence_no = sentence_no;


    for (char& c : sentence) {
        if (std::isupper(c)) {
            c = std::tolower(c);
        }
    }

    entry.sentence = sentence;

    sentences.push_back(entry);
}

vector<int> SearchEngine::computeLPS(const string &pattern)
{
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    
    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

Node *SearchEngine::search(const string pattern, int &n_matches)
{
    Node *head = nullptr;
    Node *tail = nullptr;
    n_matches = 0;
    for (char &c : patttern)
    {
        if (std::isupper(c))
        {
            c = std::tolower(c);
        }
    }
    vector<int> lps = computeLPS(pattern);

    for (const auto &entry : sentences)
    {
        const string &sentence = entry.sentence;
        int m = pattern.length();
        int n = sentence.length();
        int i = 0;
        int j = 0;

        while (i < n)
        {
            if (pattern[j] == sentence[i])
            {
                i++;
                j++;

                if (j == m)
                {
                    Node *node = new Node(entry.book_code, entry.page, entry.paragraph, entry.sentence_no, i - j);

                    if (head == nullptr)
                    {
                        head = tail = node;
                    }
                    else
                    {
                        tail->right = node;
                        tail = node;
                    }

                    j = lps[j - 1];
                    n_matches++;
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }

    return head;
}