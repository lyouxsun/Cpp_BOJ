#include <iostream>
#include <algorithm>
using namespace std;
int num, pivot, left, right;
void quickSort(int arr[], int left, int right);

int main(){
    cin >> num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    quickSort(arr, 0, num-1);
    
    for(int i=0;i<num;i++){
        cout<<arr[i]<<"\n";
    }
}

//재귀 써서 반복하기
void quickSort(int arr[], int left, int right){
    if(left>=right) {
        return;
    }
    pivot = arr[left+(right-left)/2];     
    int i=left;
    int j=right;
    
    while(i<=j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
//Q1.
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
//Q2.
    quickSort(arr, left, j);//pivot-1);
    quickSort(arr, i, right);//pivot+1, right);
}