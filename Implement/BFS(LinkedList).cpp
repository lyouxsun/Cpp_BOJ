#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static queue<int> q;

vector<vector<int>> graph(int vertex, int edge){
    vector<vector<int>> g(vertex+1);
    int tmp1, tmp2;
    for(int i=0;i<edge;i++){
        cin>>tmp1>>tmp2;
        g[tmp1].push_back(tmp2);
        g[tmp2].push_back(tmp1);
    }
    return g;
}
void BFS(vector<vector<int>> g, vector<int> visited, int start){
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()){
        int next = q.front();
        q.pop();
        cout<<"> "<<next;

        for(int i=0;i<g[next].size();i++){
            int tmp = g[next][i];
            if(!visited[tmp]){
                q.push(tmp);
                visited[tmp] = 1;
            }
        }
    }
}

int main (){
    //그래프 만들기
    int vertex, edge, start;
    cin >> vertex >> edge >> start;
    vector<vector<int>> g = graph(vertex, edge);
    vector<int> visited(vertex+1); 

    //작은수부터 방문하도록 그래프 정렬
    for(int i=1;i<=vertex;i++){
        sort(g[i].begin(), g[i].end());
    }

    //BFS수행, 결과 출력 함수
    BFS(g, visited, start);
}