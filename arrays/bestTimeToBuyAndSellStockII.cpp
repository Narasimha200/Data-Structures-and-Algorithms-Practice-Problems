#include <iostream>
#include <vector>
using namespace std;


int maxProfit(vector<int> &prices){
    int mini = prices[0];
    int currProfit = 0;
    int profit = 0;
    for(int i = 1; i < prices.size(); i++){
        if(prices[i-1] > prices[i]){
            profit += currProfit;
            mini = prices[i];
            currProfit = 0;
        }
        else{
            currProfit = prices[i] - mini;
            if(i == prices.size()-1) profit += currProfit;
        }
    }
    return profit;
}

int main(){
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
}