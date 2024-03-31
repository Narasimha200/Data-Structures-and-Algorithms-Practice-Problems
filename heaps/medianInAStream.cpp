//url:- "https://www.naukri.com/code360/problems/median-in-a-stream_975268?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar"
//level:- "Hard"
#include <bits/stdc++.h>
using namespace std;
int signum(int maxSize, int minSize)
{
    if (maxSize == minSize)
    {
        return 0;
    }
    else if (maxSize > minSize)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void getMedian(int element, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int &median)
{
    switch (signum(maxheap.size(), minheap.size()))
    {

    case 0:
        if (element > median)
        {
            minheap.push(element);
            median = minheap.top();
        }
        else
        {
            maxheap.push(element);
            median = maxheap.top();
        }
        break;
    case 1:
        if (element > median)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(element);
        }
        else
        {
            maxheap.push(element);
        }
        median = (minheap.top() + maxheap.top()) / 2;
        break;
    case -1:
        if (element > median)
        {
            minheap.push(element);
        }
        else
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(element);
        }
        median = (minheap.top() + maxheap.top()) / 2;
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    // to store all medians
    vector<int> ans;
    // create min and max heaps
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    int median = 0;

    for (int i = 0; i < n; i++)
    {
        getMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }
    return ans;
}

int main(){
    vector<int> stream = {5, 3, 8};
    vector<int> medians = findMedian(stream, stream.size());
    cout<<"Medians are: ";
    for(int e: medians){
        cout<< e << " ";
    }
    cout<<endl;
}
//Time complexity: O(n log(n))
//Space complexity: O(n)