#include <iostream>
#include <vector>
using namespace std;
class TrieNode
{
public:
    char ch;
    TrieNode *childs[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
        {
            childs[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    void insertUtil(string s, TrieNode *root)
    {
        if (s.length() <= 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = s[0] - 'a';
        // if root -> childs[index] is empty
        if (root->childs[index] == NULL)
        {
            root->childs[index] = new TrieNode(s[0]);
        }
        insertUtil(s.substr(1), root->childs[index]);
    }

public:
    Trie() : root(new TrieNode('\0')) {}
    void insert(string s)
    {
        insertUtil(s, root);
    }
};

void printWords(TrieNode *root, string &s, vector<string> &words)
{
    if (root->isTerminal)
    {
        words.push_back(s);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->childs[i] != 0)
        {
            s.push_back(root->childs[i]->ch);
            printWords(root->childs[i], s, words);
            s.pop_back();
        }
    }
}

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    vector<vector<string>> ans;
    string prefix = "";
    Trie t;
    TrieNode *prev = t.root, *curr = NULL;
    for (int i = 0; i < n; i++)
    {
        t.insert(contact[i]);
    }
    for (char &ch : s)
    {
        int index = ch - 'a';
        curr = prev->childs[index];
        if (curr != NULL)
        {
            vector<string> words;
            prefix.push_back(ch);
            printWords(curr, prefix, words);
            ans.push_back(words);
            prev = curr;
        }
        else
        {
            break;
        }
    }
    for(auto &v1: ans){
        for(auto &v2: v1){
            cout << v2 << " ";
        }
        cout << endl;
    }
}

int main()
{
    string contact[] = {"geeikistest", "geeksforgeeks",
                 "geeksfortest"};
    string s = "geeips";
    displayContacts(3, contact, s);
}