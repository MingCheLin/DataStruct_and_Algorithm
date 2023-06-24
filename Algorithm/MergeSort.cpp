#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSort(vector<int>& arr, int l, int r){
    if (l>=r)
        return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    
    for (int i=l, j=mid+1; i<=j && j<=r;){
        if (arr[i] <= arr[j])
            i++;
        else{
            int temp = arr[j];
            for (int cur = j; cur>i; cur--)
                arr[cur] = arr[cur-1];
            arr[i] = temp;
            j++;
            i++;
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
    mergeSort(arr, 0, arr.size()-1);
    printArr(arr);
    return 0;
}
