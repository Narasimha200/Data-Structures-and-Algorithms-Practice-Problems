// URL:- "https://leetcode.com/problems/count-good-numbers/description/"
class Solution
{
    int m = 1000000007;
    //Binary exponentiation
    long long Pow(int x, long long n)
    {
        if (n == 0)
            return 1;
        long long currAns = Pow(x, n / 2);
        currAns = (currAns * currAns) % m;
        if (n % 2)
            currAns = (currAns * (x % m)) % m;
        return currAns;
    }

public:
    int countGoodNumbers(long long n)
    {
        long long no5 = (n + 1) / 2;
        long long no4 = n / 2;
        return ((Pow(5, no5) % m) * (Pow(4, no4) % m)) % m;
    }
};

//TC:- O(logN)
//SC:- O(logN)