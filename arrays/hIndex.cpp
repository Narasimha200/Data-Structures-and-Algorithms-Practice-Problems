#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations)
{
    int n = citations.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int num: citations){
        pq.push(num);
    }

    int paper = 1;
    while(!pq.empty()){
        if(pq.size() >= paper){
            if(pq.top() >= paper) paper++;
            else pq.pop();
        }
        else break;
    }
    return paper - 1;
}

//TC:- N*logN either we are decreasing the size or increasing the paper
//SC:- (N)