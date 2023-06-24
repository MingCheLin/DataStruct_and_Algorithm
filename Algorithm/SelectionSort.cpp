#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SelectionSort(vector<int> &arr){
    int n = arr.size();
    for (int i=0; i<n; i++){
        int idx = i;
        for (int j=i+1; j<n; j++){
            if (arr[j]<arr[idx]){
                idx = j;
            }
        }
        swap(arr[idx], arr[i]);
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
    SelectionSort(arr);
    printArr(arr);
    return 0;
}
