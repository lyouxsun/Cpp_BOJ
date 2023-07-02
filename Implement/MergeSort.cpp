#include <iostream>
using namespace std;
int num, order, mid, i, j, k;

static void merge(int* arr, int left, int mid, int right){
    
    int sorted[right-left+1];
    i=left;
    j=mid+1;    
    //////////merge는 각각 정렬된 두 배열을 합하는 함수니까 j가 mid에서부터 시작해야함
    ////////// -> 근데 왜 mid+1?? 
    k=0;        ///////////sorted배열 인덱스

    //while을 조건별로 나눠줘야한다!!!!!!
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            sorted[k++]=arr[i++];
        }
        else{
            sorted[k++]=arr[j++];
        }
    }
    while(i<=mid){  ////////////i<=mid는 성립하지만, j<=right는 성립 안할때
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
    //////////////// 이부분 //////////////////
    if(left>=right){
        return;
    }
    /////////////////////////////////////////
    mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, num-1);
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
}