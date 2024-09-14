#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    vector<string> currLevelUsedWords;
    vector<vector<string>> ans;
    q.push({beginWord});
    currLevelUsedWords.push_back(beginWord);
    st.erase(beginWord);
    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            vector<string> vec = q.front();
            string word = vec.back();
            q.pop();
            if (word == endWord)
            {
                ans.push_back(vec);
                continue;
            }
            for (int i = 0; i < word.size(); i++)
            {
                int pre = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        vec.push_back(word);
                        q.push(vec);
                        currLevelUsedWords.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = pre;
            }
        }
        // removing all the words which are used
        for (auto &word : currLevelUsedWords)
        {
            st.erase(word);
        }
        currLevelUsedWords.clear();
    }
    return ans;
}