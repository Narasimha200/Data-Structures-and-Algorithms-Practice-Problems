#include <iostream>
using namespace std;
//MAX HEAP
void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left <= size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
void printArray(int arr[], int size){
    for(int i = 1; i <= size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // we are using 1 based indexing
    int arr[] = {-1, 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int size = sizeof(arr)/sizeof(arr[0]) - 1;
    for(int i = size/2; i > 0; i--){
        heapify(arr, size, i);
    }
    printArray(arr,size);
}