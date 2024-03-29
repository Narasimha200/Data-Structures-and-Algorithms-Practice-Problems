//url:- "https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1"
//level:- "Easy"
#include <iostream>
#include <queue>
using namespace std;
long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    for (int i = 0; i < n; i++)
    {
        heap.push(arr[i]);
    }

    long long cost = 0;

    while (heap.size() > 1)
    {
        long long fMin = heap.top();
        heap.pop();
        long long sMin = heap.top();
        heap.pop();
        long long sum = fMin + sMin;
        cost += sum;

        heap.push(sum);
    }
    return cost;
}

int main(){
    long long arr[] = {4, 3, 2, 6};
    cout<<"Min cost to join all the rops: " << minCost(arr, 4);
}

// TimeComplexity:- O(nlog(n))
// SpaceComplexity:- O(n)