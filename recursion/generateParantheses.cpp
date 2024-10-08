#include <bits/stdc++.h>
using namespace std;

void generate(int n, string &validpar, vector<string> &ans, int left, int right){
    if(validpar.length() == 2 * n){
        ans.push_back(validpar);
    }

    if(left < n){
        validpar.push_back('(');
        generate(n, validpar, ans, left+1, right);
        validpar.pop_back();
    }

    if(right < left){
        validpar.push_back(')');
        generate(n, validpar, ans, left , right+1);
        validpar.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string validpar;
    generate(n, validpar, ans, 0, 0);
    return ans;
}

int main(){
    generateParenthesis(3);
}

//TC:- O(2 ^ N)
//SC:- O(2 * N)