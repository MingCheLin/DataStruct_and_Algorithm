#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InsertionSort(vector<int> &arr){
    int n = arr.size();
    for (int i=1; i<n; i++){
        int k = arr[i], j=i-1;
        while (j>=0 && k<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
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
    InsertionSort(arr);
    printArr(arr);
    return 0;
}
