#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BubbleSort(vector<int> &arr){
    int n = arr.size();
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<i; j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
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
    BubbleSort(arr);
    printArr(arr);
    return 0;
}
