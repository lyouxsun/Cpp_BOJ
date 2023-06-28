#include <iostream>
#include <cmath>
using std::cout;
using std::cin;

int main(){
    int start, end, first;;
    int sum=0;
    cin >> start;
    cin >> end;

    for(int i=start;i<=end;i++){
        double temp1 = sqrt(i);
        int temp2 = sqrt(i);
        if(temp1==(int)temp2){
            if(sum==0) first=i;
            sum+=i;
        }
    }
    if(sum==0) cout<<"-1";
    else {
        cout << sum << "\n" << first;
    }
}