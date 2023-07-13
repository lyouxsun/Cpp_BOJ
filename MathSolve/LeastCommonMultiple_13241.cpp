/**
 * 1. 두개의 수 중 하나가 배수인 경우 -> 답:배수 (두수중 더 큰수) 
 * 2. 최대공약수가 존재하는 경우 -> 답:두수의곱%최대공약수
 * 3. 최대공약수가 존재하지 않는 경우 -> 답:두수의곱
*/
#include <iostream>
using namespace std;

int main(void){
    long long int a, b;
    cin>>a>>b;
    
    //1
    if((a/b>0&&a%b==0) || (b/a>0&&b%a==0)){
        if(a>=b) cout<<a;
        else cout<<b;
        return 0;
    }

    //2
    int smaller, i;
    if(a<b) smaller=a;
    else smaller=b;

    for(i=smaller;i>0;i--){
        if((a%i==0)&&(b%i==0)){
            cout<<a*b/i;
            return 0;
        }
    }

    //3
    cout<<a*b;
}