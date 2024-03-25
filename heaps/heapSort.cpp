//url:- "https://www.geeksforgeeks.org/problems/heap-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
//level:- "Medium"
#include <iostream>
using namespace std;

// Heapify function to maintain heap property.
void heapify(int arr[], int n, int i)
{
    int index = i;
    while (index >= 0)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            index = largest;
        }
        else{
            break;
        }
    }
}
// Function to build a Heap from array.
void buildHeap(int arr[], int n)
{

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    while (n > 1)
    {
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(arr, n, 0);
    }
}

int main()
{
    int arr[] = {1, 3, 9, 6, 1, 4, 2, 6, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);
    // printing sorted array
    cout << "Sorted arrays" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Time complexity:- O(nlog(n))
// Space complexity:- O(1)