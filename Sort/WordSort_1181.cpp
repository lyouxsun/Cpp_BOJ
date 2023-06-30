#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int num;
    cin >> num;
    string arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    sort(arr, arr+num);

    for(int i=0;i<num;i++){
        for(int j=1;i+j<num;j++){
            const char *str1=arr[i].c_str();
            const char *str2=arr[i+j].c_str();
            if(i+j==num-1){
                arr[i+j]="\n";
            }
            if(strcmp(str1, str2)==0){
                arr[i+j]=arr[i+j+1];
            }
        }
    }


    for(int i=0;i<num;i++){
        if(arr[i+1]=="\0"){
            cout<<arr[i];
            break;
        }
        cout<<arr[i]<<"\n";
    }
}