#include <iostream>
#include <unordered_map>
using namespace std;

//LINK:- "https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings"
long long int countAtMost(string &s, int k)
{
    long long count = 0;
    int left = 0, right = 0;
    int mp[26] = {0};
    int dist = 0;
    while (right < s.length())
    {
        mp[s[right] - 'a']++;
        if (mp[s[right] - 'a'] == 1)
            dist++;
        while (dist > k)
        {
            mp[s[left] - 'a']--;
            if (mp[s[left] - 'a'] == 0)
            {
                dist--;
            }
            left++;
        }
        count += (right - left + 1);
        right++;
    }
    return count;
}

long long int substrCount(string s, int k)
{
    return countAtMost(s, k) - countAtMost(s, k - 1);
}

//TC:- O(N)
//sC:- O(26) -> O(1)