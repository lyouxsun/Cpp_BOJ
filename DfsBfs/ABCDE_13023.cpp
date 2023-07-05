//그래프의 인덱스는 0~vertex-1!!!
//for문에서 범위를 i=0 ~ i<vertex 로 할것!
/*
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
*/
#include <iostream>
#include <vector>
using namespace std;
static int cnt=0;


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

void DFS(vector<vector<int>>& v, vector<int>& visited, int startVertex){
    if(cnt>=4){
        return;
    }
    if(visited[startVertex]){
        return;
    }
    visited[startVertex]=1;
    cnt++;

    
    for(int i:v[startVertex]){
        if(!visited[i]){
            DFS(v,visited, i);
            if(cnt<4) cnt=0;
        }
    }
}

int main(){
    int vertex, edge;
    cin>>vertex>>edge;
    vector<vector<int>> g = graph(vertex, edge);

    for(int i=0;i<vertex;i++){
        vector<int> visited(vertex, 0);
        DFS(g, visited, i);
        if(cnt>=4){
            cout<<"1";
            break;
        }
    }
    if(cnt<4){
        cout<<"0";
    }
}