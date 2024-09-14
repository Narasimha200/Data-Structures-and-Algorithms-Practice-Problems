#include <queue>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    unordered_set<string> s;
    queue<pair<string, int>> q;

    q.push({startWord, 1});
    for(string &str: wordList){
        s.insert(str);
    }

    while (!q.empty())
    {
        string word = q.front().first;
        int len = q.front().second;
        q.pop();
        if(word == targetWord) return len;
        for(int i = 0; i < word.length(); i++){
            char prev = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(s.count(word)){
                    q.push({word, len + 1});
                    s.erase(word);
                }
            }
            word[i] = prev;
        }
    }
    return 0;
}
//TC:- O(N * M * 26)
//SC:- O(N * WordLength)