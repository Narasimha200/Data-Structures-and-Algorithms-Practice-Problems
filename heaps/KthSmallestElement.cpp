// url:- "https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1"
// level:- "Medium"
#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int size, int k)
{

    priority_queue<int> heap;

    for (int i = 0; i < k; i++)
    {
        heap.push(arr[i]);
    }

    for (int i = k; i < size; i++)
    {
        if (arr[i] < heap.top())
        {
            heap.pop();
            heap.push(arr[i]);
        }
    }

    return heap.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int result = kthSmallest(arr, size, k);
    cout<< "Kth Smallest element :" << result << endl;
}

// time complexity:- O(n*log(n))
// space complexity:- O(k)