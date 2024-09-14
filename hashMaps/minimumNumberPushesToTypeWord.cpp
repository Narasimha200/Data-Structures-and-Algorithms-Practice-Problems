#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int minimumPushes(string word)
{
    vector<int> freq(26, 0);
    int pos = 0;
    int cost = 0;
    for(char ch: word) freq[ch - 'a']++;
    sort(freq.begin(), freq.end(), greater<int>());
    for(int i = 0; i < freq.size(); i++){
        cost = cost + (pos / 8 + 1)*freq[i];
        pos++;
    }
    return cost;
}
int main(){
    cout << minimumPushes("abzaqsqcyrbzsrvamylmyxdjl");
}