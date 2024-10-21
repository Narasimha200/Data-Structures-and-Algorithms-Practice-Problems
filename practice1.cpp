#include <bits/stdc++.h>
using namespace std;

int main(){
    string X, Y;
    cin >> X >> Y;
    int s, r;
    cin >> s >> r;
    unordered_set<string> s;
    for(int i = 0; i < Y.length(); i++){
        string str = "";
        for(int j = i; j < Y.length(); j++){
            str.push_back(Y[j]);
            s.insert(str);
        }
    }
    string temp = "";
    for(int i = 0; i < X.length(); i++){
        temp.push_back(X[i]);
        // if original string exists
    }
}