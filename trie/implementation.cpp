#include <iostream>
using namespace std;

// structure of a TrieNode
class TrieNode{
    public:
    char ch;
    bool isTerminal;
    TrieNode* childs[26];
    TrieNode(char ch){
        this -> ch = ch;
        isTerminal = false;
        for(int i = 0; i < 26; i++){
            childs[i] = NULL;
        }
    }
};

class Trie{
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string word){
        insertUtil(root, word);
    }

    bool search(string word){
        return searchUtil(root, word);
    }

    private:
    TrieNode *root;

    void insertUtil(TrieNode *root, string word){
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'A';
        if(root -> childs[index] == NULL){
            root -> childs[index] = new TrieNode(word[0]);
        }
        insertUtil(root -> childs[index], word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root -> isTerminal;
        }
        int index = word[0] - 'A';
        if(root -> childs[index] != NULL){
            return searchUtil(root -> childs[index], word.substr(1));
        }
        return false;
    }
};

int main(){
    Trie t;
    t.insert("ABCDE");
    t.insert("ABDTE");
    cout << (t.search("ABCDE")? "Found":"NOT FOUND") << endl;
    cout << (t.search("ABDTEE")? "Found":"NOT FOUND") << endl;
}