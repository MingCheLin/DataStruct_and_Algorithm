#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapifyDown(vector<int> &arr, int size, int rootInd) {
    if (size <= 1 or rootInd < 0 or rootInd >= size - 1) return;
    int keyInd = rootInd, leftChildInd = 2 * rootInd + 1, rightChildInd = 2 * rootInd + 2;
    if (leftChildInd < size and (arr[leftChildInd] > arr[keyInd]))
        keyInd = leftChildInd;
    if (rightChildInd < size and (arr[rightChildInd] > arr[keyInd]))
        keyInd = rightChildInd;
    if (arr[keyInd] != arr[rootInd]) {
        swap(arr[rootInd], arr[keyInd]);
        heapifyDown(arr, size, keyInd);
    }
}

void heapifyArray(vector<int> &arr) {
    int size = arr.size();
    if (size <= 1) return;
    int tailRootInd = (size >> 1) - 1;
    for (int rootInd = tailRootInd; rootInd >= 0; rootInd--)
        heapifyDown(arr, size, rootInd);
}

void heapSort(vector<int> &arr) {
    if (arr.size() <= 1) return;
    heapifyArray(arr);
    for (int size = arr.size() - 1; size; size--) {
        swap(arr[size], arr[0]);
        heapifyDown(arr, size, 0);
    }
}
    
void printArr(vector<int> &arr){
    for (int i=0; i<arr.size(); i++){
      cout<<arr[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {2,5,4,9,8,7,1,6,3};
    heapSort(arr);
    printArr(arr);
    return 0;
}
