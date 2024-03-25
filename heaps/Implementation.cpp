#include <iostream>
using namespace std;

class heap{
    int arr[100];
    int size;
    public:
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int value){
        size = size + 1;
        int index = size;
        arr[index] = value;

        // loop until heap condition is not satiesfied i.e arr[parent] < arr[index]
        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
            }
            else{
                return;
            }
            index = parent;
        } 
    }
    void heapify(int *arr, int size, int i){
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if(left <= size && arr[largest] < arr[left]){
            largest = left;
        }
        if(right <= size && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != i){
            swap(arr[i],arr[largest]);
            heapify(arr, size, largest);
        }
    }

    void deleteNode(){
        if(size == 0){
            cout << "Not enough elements to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        --size;
        heapify(arr, size, 1);
    }
    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteNode();
    h.print();
    return 0;
}