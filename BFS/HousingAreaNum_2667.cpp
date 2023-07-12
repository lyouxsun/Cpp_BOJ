#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
//#include <stdio.h>
#include <string>
using namespace std;

static int nX[4] = {-1, 0, 1, 0};
static int nY[4] = {0, -1, 0, 1};

int BFS(vector<vector<int>>& arr, int size, int X, int Y){
    queue<pair<int, int>> q;
    q.push(make_pair(X, Y));     
    //q.push(pair<int, int>(X, Y));
    arr[X][Y]=0;
    int cnt=0;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        cnt++;

        for(int i=0;i<4;i++){
            int nextX = curX + nX[i];
            int nextY = curY + nY[i];
            if(nextX>=0 && nextX<size && nextY>=0 && nextY<size){   //좌표 유효성 검사
                if(arr[nextX][nextY]==1){       //아직 탐색하지 않은 노드일 때
                    arr[nextX][nextY] = 0;
                    q.push(make_pair(nextX, nextY));    
                    //q.push(pair<int, int>(nextX, nextY));
                }
            }
        }
    }
    return cnt;
}

int main(){
    //배열 입력받기
    int size;
    cin>>size;
    //scanf("%d", &size);
    vector<vector<int>> arr(size, vector<int>(size));
    for(int i=0;i<size;i++){
        string row;
        cin>>row;
        //scanf("%s", &row);
        for(int j=0;j<size;j++){
            arr[i][j]=(row[j]-'0');
        }
    }
    
    //그래프 탐색하기
    vector<int> counts;  //i번째 연결요소의 요소개수
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[i][j]==1){
                counts.push_back(BFS(arr, size, i, j));
            }
        }
    }
    //cnt배열 정렬
    sort(counts.begin(), counts.end());
    
    cout<<counts.size()<<'\n';
    //printf("%d", counts.size());
    for(int i:counts){
        cout<<i<<'\n';
        //printf("\n%d", counts[i]);
    }
}