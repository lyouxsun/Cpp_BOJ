/**
 *** BFS(큐) 이용하여 최단경로 구하기
 * visited배열 필요 없이, 방문할 노드는 큐에 넣어준 후에 arr[i][j]=0으로 바꿔주기
 * 최단경로는 static변수 이용해서 계속 ++해주기
*/

#include <cstdio>
    //#include <string>
#include <algorithm>
#include <vector>
#include <queue>    
    //#include <utility>  : pair사용시 필요, but queue의 속성으로 쓰일 땐 필요없음
using namespace std;

static queue<pair<int, int>> q;
static int nextX[4]={1, 0, -1, 0};
static int nextY[4]={0, 1, 0, -1};
static int N, M, cnt=2;

void BFS(vector<vector<int>>& arr){
    q.push(make_pair(0, 0));

    while(!q.empty()){
        int nowX=q.front().first;
        int nowY=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int x = nowX+nextX[i];
            int y = nowY+nextY[i];

            if(x>=0 && y>=0 && x<N && y<M){       //좌표 유효성 검사
                if(!(x==0&&y==0) && arr[x][y]==1){    //방문 노드 검사
                    arr[x][y]=arr[nowX][nowY]+1;        //깊이 업데이트
                    q.push(make_pair(x, y));
                }
            }
        }
    }
}

int main (){
    
    scanf("%d %d", &N, &M);
    vector<vector<int>> arr(N);
    char str[N][M];
    for(int i=0;i<N;i++){
        scanf("%s", &str[i]);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i].push_back(str[i][j]-'0');
        }
    }

    BFS(arr);
    printf("%d", arr[N-1][M-1]);
}