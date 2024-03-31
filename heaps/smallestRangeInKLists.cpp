#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class node
{
public:
    int element, row, col;
    node(int elements, int row, int col)
    {
        this->element = elements;
        this->row = row;
        this->col = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->element > b->element;
    }
};
pair<int, int> findSmallestRange(vector<vector<int>>& KSortedArray, int n, int k)
{
    // code here
    // create a heap
    priority_queue<node *, vector<node *>, compare> minh;
    int start = 0, end = INT_MAX;

    int mini = 0, maxi = INT_MIN;

    // push first elements of each list to heap
    for (int i = 0; i < k; i++)
    {
        int element = KSortedArray[i][0];
        maxi = max(maxi, element);
        minh.push(new node(element, i, 0));
    }

    while (!minh.empty())
    {
        node *temp = minh.top();
        mini = temp->element;
        int row = temp->row;
        int col = temp->col;
        minh.pop();
        delete temp;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        if (col < n - 1)
        {
            minh.push(new node(KSortedArray[row][col + 1], row, col + 1));
            maxi = max(maxi, KSortedArray[row][col + 1]);
        }
        else
        {
            break;
        }
    }

    return {start, end};
}

int main(){
    vector<vector<int>> v = {
        {1, 3, 5, 7, 9},
        {0, 2, 4, 6, 8},
        {2, 3, 5, 7, 11}
    };
    pair<int, int> ans = findSmallestRange(v, v[0].size(), v.size());
    cout<<"Smallest range is : " << "[ " << ans.first << " <-> " << ans.second << " ]" << endl;
    return 0;
}