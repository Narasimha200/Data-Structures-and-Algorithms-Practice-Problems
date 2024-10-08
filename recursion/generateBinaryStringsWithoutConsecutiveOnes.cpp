#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<string> ans;
    void binaryStrings(int num, string &temp){
        if(temp.length() == num){
            ans.push_back(temp);
            return;
        }
        temp.push_back('0');
        binaryStrings(num, temp);
        temp.pop_back();
        
        if(temp.empty() || temp.back() == '0'){
            temp.push_back('1');
            binaryStrings(num, temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateBinaryStrings(int num){
        //Write your code
        string temp = "";
        binaryStrings(num, temp);
        return ans;
    }
};
//TC:- O(2 ^ N)
//SC:- O(N)