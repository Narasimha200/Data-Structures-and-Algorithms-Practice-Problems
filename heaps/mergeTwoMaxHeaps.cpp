// url:- "https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1"
// Level:- "Easy"

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here
    a.resize(n + m);

    for (int i = 0; i < b.size(); i++)
    {
        a[n + i] = b[i];
    }
    // heapify the total vector
    int size = a.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(a, size, i);
    }
    return a;
}

int main(){
    vector<int> v1 = {10, 5, 6, 2};
    vector<int> v2 = {12, 7, 9};
    vector<int> ans = mergeHeaps(v1, v2, v1.size(), v2.size());
    cout<<"Max heap: "<<endl;
    for(int item:ans){
        cout<<item<<" ";
    }
}
//Time complexity:- O(n + m)
//space complexity:- O(m)