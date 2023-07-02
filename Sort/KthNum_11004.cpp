#include <iostream>
using namespace std;
int num, order;

static void merge(int* arr, int left, int mid, int right){
    
    int sorted[right-left+1];
    int i, j, k;
    i=left;
    j=mid+1;
    k=0;

    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            sorted[k++]=arr[i++];
        }
        else{
            sorted[k++]=arr[j++];
        }
    }
    while(i<=mid){  
        sorted[k++]=arr[i++];
    }
    while(j<=right){
        sorted[k++]=arr[j++];
    }

    for(int i=left; i<=right; i++){
        arr[i]=sorted[i-left];
    }
}

static void mergeSort(int arr[], int left, int right){
    if(left>=right){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>num>>order;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, num-1);
    cout<<arr[order-1];
}