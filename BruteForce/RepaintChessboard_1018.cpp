//함수형 프로그래밍ㄱㄱ!!!!!
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[50][50];

int BW(int x, int y){   //x,y는 8*8의 시작점
    int cnt=0;
    for(int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if((i+j)%2==0){     //B일 때
                if(board[x+i][y+j]==0) cnt++;
            }
            else{
                if(board[x+i][y+j]==1) cnt++;
            }
        }
    }
    return cnt;
}

int WB(int x, int y){   //x,y는 8*8의 시작점
    int cnt=0;
    for(int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if((i+j)%2==0){
                if(board[x+i][y+j]==1) cnt++;
            }
            else{
                if(board[x+i][y+j]==0) cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int a, b, tempAnswer;    
    int answer=100000000;
    cin >> a >> b;
    char tmp;
    board[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>tmp;
            if(tmp=='B'){
                board[i][j]=1;
            }else board[i][j]=0;
        }
    }

    for(int i=0;i+8<=a;i++){
        for(int j=0;j+8<=b;j++){
            tempAnswer=min(BW(i,j), WB(i,j));
            //cout<<"i:"<<i<<" j:"<<j<<" BW:"<<BW(i, j)<<" WB:"<<WB(i,j)<<"\n";
            answer=min(answer, tempAnswer);
        }
    }
    cout<<answer;
}