/**
 * 이동 칸의 개수를 따로 저장하는 2차원 배열(depth) 필요 (현재의 depth를 해당 칸에 저장 -> 목표지점에 도달했을 때 해당칸의 값만 출력해주면 된다.)
 * -> depth를 새로 만들지 말고 arr를 재활용하기
 * 방문여부 확인하는 배열(visited) 필요 (0, 1)
 * queue는 언제 필요한걸까.. -> 다음에 어떤 노드를 방문할지 저장해두기
 * 
*/

#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
//#include <utility>  : pair사용시 필요, but queue의 속성으로 쓰일 땐 필요없음

using namespace std;
static queue<pair<int, int>> q;
static int nextX[4]={1, 0, -1, 0};
static int nextY[4]={0, 1, 0, -1};
static int N, M;

void BFS(vector<vector<int>> arr, vector<vector<int>> visited, int a, int b){
    q.push(pair<int, int>(a, b));
    visited[a][b]=1;

    while(!q.empty()){
        int nowX=q.front().first;
        int nowY=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int x = nowX+nextX[i];
            int y = nowY+nextY[i];

            if(x>=0 && y>=0 && x<N && y<M){       //좌표 유효성 검사
                if(arr[x][y]==1 && visited[x][y]==0){    //방문 노드 검사
                    visited[x][y]=1;
                    arr[x][y]=arr[nowX][nowY]+1;        //깊이 업데이트
                    q.push(pair<int, int>(x, y));
                }
            }
        }
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    scanf("%d %d", &N, &M);
    vector<vector<int>> arr;
    vector<vector<int>> visited;
    string str;

    //미로배열, 방문여부배열 크기조정 & 초기화
    for(int i=0;i<N;i++){
        arr[i].resize(M, 0);
        visited[i].resize(M, 0);
    }

    for(int i=0;i<N;i++){
        scanf("%s", &str);
        for(int j=0;j<M;j++){
            arr[i].push_back(str[j]-'0');
        }
        str="";
    }

    BFS(arr, visited, 0, 0);
    printf("%d", arr[N-1][M-1]);
}