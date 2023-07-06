//그래프의 인덱스는 0~vertex-1!!!
//for문에서 범위를 i=0 ~ i<vertex 로 할것!
/*
매번 다른 노드를 시작으로 DFS를 실행할 때마다 visited, cnt=0으로 초기화해야한다.
cnt언제 초기화? depth가 내려가지 않는다면 ++를 하면 안됨다.

그래프에 사이클이 생기면

5 4
0 1
0 2
2 3
3 4
답 : 1

5 4
0 1
1 2
2 3
3 0
답 : 0

5 5
0 1
1 3
1 2
2 3
3 4
답 : 1
*/
#include <iostream>
#include <vector>
using namespace std;
static int depth=1;

vector<vector<int>> graph(int vertex, int edge){
    int tmp1, tmp2;
    vector<vector<int>> g(vertex);    //(vertex)개의 행을 갖는 벡터 선언 
    for(int i=0;i<edge;i++){
        cin>>tmp1>>tmp2;
        g[tmp1].push_back(tmp2);
        g[tmp2].push_back(tmp1);
    }
    return g;
}

void DFS(vector<vector<int>>& v, vector<int> visited, int start){
    if(depth>=5){
        return;
    }
    visited[start]=1;

    for(int i:v[start]){
        int next = *(v[start].begin()+i-1);
        if(!visited[next]){
            depth++;
            DFS(v, visited, next);
        }
    }
    /*
    if(depth>=5){
        return;
    } else depth--;
    */
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int vertex, edge;
    cin>>vertex>>edge;
    vector<vector<int>> g = graph(vertex, edge);

    for(int i=0;i<vertex;i++){
        vector<int> visited(vertex, 0);
        DFS(g, visited, i);

        if(depth>=5){
            cout<<"1";
            break;
        }
    }
    if(depth<5){
        cout<<"0";
    }
}