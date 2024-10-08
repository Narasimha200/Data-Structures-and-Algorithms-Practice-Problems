
//LINK:- "https://leetcode.com/problems/reverse-words-in-a-string/"
string reverseWords(string s)
{
    string ans;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            ans.push_back(s[i]);
        }
        else if (i < n - 1 && s[i + 1] != ' ' && !ans.empty())
        {
            ans.push_back(s[i]);
        }
    }
    int start = 0;
    int i = 0;
    while (i < ans.length())
    {
        if (i == ans.length() - 1 || ans[i + 1] == ' ')
        {
            reverse(ans.begin() + start, ans.begin() + i + 1);

            i = i + 2;
            start = i;
        }
        else
        {
            i = i + 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}