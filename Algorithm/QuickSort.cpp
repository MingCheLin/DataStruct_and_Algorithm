#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void partition(vector<int> &arr, int l, int r){
      if (l>=r){
          return;
      }
      int pivot = arr[r], j = l;
      for (int i=l; i<r-1; i++){
            if (arr[i]<pivot){
                  swap(arr[i], arr[j]);
                  j++;
            }
      }
      swap(arr[j], arr[r]);
      partition(arr, l, j-1);
      partition(arr, j+1, r);
}

void QuickSort(vector<int> &arr){
      int n = arr.size();
      partition(arr, 0, n-1);
}

void printArr(vector<int> &arr){
      for (int i=0; i<arr.size(); i++){
          cout<<arr[i]<<' ';
      }
      cout<<endl;
}
int main() {
      vector<int> example = {3,2,4,1,6,5,7,9,8,5};
      printArr(example);
      QuickSort(example);
      printArr(example);
}


