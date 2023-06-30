/*
나누는 수가 0인 경우를 생각하지 못했다!!
연산할 때 (나누기 0)은 항상 주의할것!!!
*/
#include <iostream>
using namespace std;

int main(){
    int x, y, a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    //x==(c-b*y)/a==(f-e*y)/d;
    for(y=-999;y<1000;y++){
        if((c-b*y)*d==(f-e*y)*a){
            if(a==0){
                x=(f-e*y)/d;
            }
            else {
                x=(c-b*y)/a;
            }
            break;
        }
    }
    cout<<x<<" "<<y;
}
