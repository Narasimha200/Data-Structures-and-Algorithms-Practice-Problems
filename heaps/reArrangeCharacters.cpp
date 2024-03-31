//url:- "https://www.geeksforgeeks.org/problems/rearrange-characters4649/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
//level:- "Medium"
#include <bits/stdc++.h>
using namespace std;
string reArrangeString(string str)
{
    // code here
    unordered_map<char, int> freq;
    for (char ch : str)
    {
        freq[ch]++;
    }
    priority_queue<pair<int, char>> maxheap;

    for (auto p : freq)
    {
        maxheap.push({p.second, p.first});
    }

    string s;
    pair<int, char> prev = {-1, '#'};
    while (!maxheap.empty())
    {
        pair<int, char> temp = maxheap.top();
        maxheap.pop();
        s.push_back(temp.second);

        if (prev.first > 0)
        {
            maxheap.push(prev);
        }

        temp.first--;
        prev = temp;
    }
    if (str.length() == s.length())
    {
        return s;
    }
    else
    {
        return "-1";
    }
}

int main(){
    string str = "aaabbbccc";
    string ans = reArrangeString(str);
    if(ans != "-1"){
        cout << "reArranged characters are: " << ans <<  endl;
    }
    else{
        cout << "No it is not possible to rearrange the characters" << endl;
    }
}
//Time complexity:- O(n log(26))
//Space compleixty:- O(n)