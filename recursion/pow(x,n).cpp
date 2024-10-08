
//LINK:- "https://leetcode.com/problems/powx-n/"

double Pow(double x, long long n)
{
    if (n == 0)
        return 1;
    double currAns = Pow(x, n / 2);
    currAns = currAns * currAns;
    if (n % 2)
        currAns *= x;
    return currAns;
}

double myPow(double x, int n)
{
    long long nn = n;
    if (nn < 0)
        nn *= -1;
    double ans = Pow(x, nn);
    if (n < 0)
        ans = 1 / ans;
    return ans;
}

//TC:- O(longN)
//SC:- O(longN)