//url:- "https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1"
//level:- "Easy"
#include <iostream>
using namespace std;
//------------------------- bruteforce ------------------------
string longestCommonPrefix(string arr[], int N)
{
    // your code here
    // loop through every character of string
    int i, j;
    for (i = 0; i < arr[0].length(); i++)
    {
        // traverse the tottal array
        for (j = 0; j < N; j++)
        {
            if (arr[j][i] != arr[0][i])
            {
                break;
            }
        }
        if (j < N)
        {
            break;
        }
    }
    string prefix = arr[0].substr(0, i);
    return (prefix == "" ? "-1" : prefix);
}
//Time complexity:- O(N * min(arr))
//space complexity:- O(min(arr)) for result.
//-------------------------------------------------------------------------

//-------------- Using Trie -----------------------------------
class TrieNode{
    public:
    char ch;
    TrieNode* childs[26];
    bool isTerminal;
    int childCount;
    TrieNode(char ch){
        this -> ch = ch;
        for(int i = 0; i < 26; i++){
            childs[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie{
    public:
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        if(root -> childs[index] == NULL){
            root -> childs[index] = new TrieNode(word[0]);
            root -> childCount++;
        }
        insertUtil(root -> childs[index], word.substr(1));
    }
    void insert(string s){
        insertUtil(root, s);
    }
};

string findLongestCommonPrefix(TrieNode *root, string word){
    string ans;
    for(char ch: word){
        if(root -> isTerminal == false && root -> childCount == 1){
            ans.push_back(ch);
        }
        else{
            break;
        }
        root = root -> childs[ch - 'a'];
    }
    return ans;
}
int main()
{
    string arr[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
    //longest common prefix using bruteforce
    // cout << longestCommonPrefix(arr, 4) << endl;
    //longest common prefix using Trie
    Trie *t = new Trie();
    for(string &s: arr){
        t -> insert(s);
    }
    cout << findLongestCommonPrefix(t -> root, arr[0]) << endl;
}