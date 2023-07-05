#include <iostream>
#include <vector>
using namespace std;
static int cycle;
static vector<vector<int>> v;
void DFS(int a, int b);
int primeNum(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>cycle;
    v.resize(2);    //2차원 벡터 크기 설정
    v[0]={2, 3, 5, 7};
    v[1]={1, 3, 5, 7, 9};

    for(int i=0;i<4;i++){   //2, 3, 5, 7일 때 차례대로 돌려보기
        DFS(v[0][i], 1);
    }
}

//판별해야하는 숫자 , 현재 자릿수
void DFS(int a, int b){
    if(primeNum(a)){
        if(b==cycle){
            cout<<a<<"\n";
            return;
        }
        else{
            for(int i=0;i<5;i++){   //1, 3, 5, 7, 9일 때 차례대로 돌려보기
                DFS(a*10+v[1][i], b+1);
            }
        }
    }
}

int primeNum(int a){
    for(int i=2;i<a;i++){
        if(a!=2 && a%i==0){
            return 0;   //거짓(소수가 아니다)
        }
    }
    return 1;   //참(소수이다)
}