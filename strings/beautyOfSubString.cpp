
//LINk:- "https://leetcode.com/problems/sum-of-beauty-of-all-substrings/"
int beautySum(string s)
{
    int beauty = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;
            int maxi = INT_MIN, mini = INT_MAX;
            for (int k = 0; k < 26; k++)
            {
                if (freq[k] == 0)
                    continue;
                if (freq[k] > maxi)
                    maxi = freq[k];
                if (freq[k] < mini)
                    mini = freq[k];
            }
            beauty += maxi - mini;
        }
        cout << endl;
    }
    return beauty;
}