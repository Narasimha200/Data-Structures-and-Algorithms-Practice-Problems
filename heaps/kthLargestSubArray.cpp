//ulr:- "https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1"
//level:- "Medium"

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthLargest(vector<int> &Arr, int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += Arr[j];
            if (heap.size() < K)
            {
                heap.push(sum);
            }
            else
            {
                if (sum > heap.top())
                {
                    heap.pop();
                    heap.push(sum);
                }
            }
        }
    }

    return heap.top();
}

int main()
{
    vector<int> arr = {-4, 5, -1, 0, 3};
    int n = 5;
    int k = 3;
    cout<<"Kth Largest SubArray is: " << kthLargest(arr, n, k) << endl;

}
//Time complexity:- O(N^2 * log K)
//Space complexity:- O(k)