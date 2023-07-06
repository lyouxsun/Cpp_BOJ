//vertex는 1~vertex번 이라고 가정 -> for문에서 i<=vertex 로 하기!!!
/**
 * 작은 수부터 순차적으로 방문하도록 하기 위해 DFS전에 그래프의 열을 오름차순으로 정렬해주었다.
 * -> 이 부분이 꼭 필요할까?? ㅇㅇ 정렬하는거 까먹지마라ㅡㅡ
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> visited;

vector<vector<int>> graph(int vertex, int edge){
    vector<vector<int>> g(vertex+1);
    int tmp1, tmp2;
    for(int i=1;i<=edge;i++){
        cin>>tmp1>>tmp2;
        g[tmp1].push_back(tmp2);
        g[tmp2].push_back(tmp1);
    }
    return g;
}

void DFS(vector<vector<int>> g, int vertex, int start){
    if(visited[start]) return;
    visited[start]=1;
    cout<<" > "<<start;
    for(int i=0;i<g[start].size();i++){
        int next = g[start][i];
        DFS(g, vertex, next);
        //cout<<"next: "<< g[start][i]<<"\n";
    }
}

int main(){
    int vertex, edge, startVertex;
    cin >> vertex >> edge >> startVertex;
    vector<vector<int>> g = graph(vertex, edge);
    for(int i=1;i<=vertex;i++){
        sort(g[i].begin(), g[i].end());
    }
    visited.resize(vertex+1, 0);

    //DFS순서대로 출력하는 부분
    DFS(g, vertex, startVertex);
}