/**
 * vertex는 1~vertex번 이라고 가정 -> for문에서 i<=vertex 로 하기!!!
 * 오름차순으로 정점을 방문하라는 조건 + 메모리 초과 때문에 재귀가 아닌 스택을 써야하는 상황
 * -> 벡터를 정렬할 때, 내림차순으로 정렬하면 stack.back에는 가장 작은 수가 존재!!!
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int cnt=1;
static vector<int> visited;
static vector<int> order;

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

void DFS(vector<vector<int>>& g, int vertex, int start){
    vector<int> stack;
    stack.push_back(start);
    while(!stack.empty()){
        int current = stack.back();
        stack.pop_back();
        if(visited[current]) continue;
        visited[current]=1;
        order[current]=cnt;
        cnt++;

        for(int i=0;i<g[current].size();i++){
            int next = g[current][i];
            if(!visited[next]) {
                stack.push_back(next);
            }
        }
    }
}

bool compare(int a, int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int vertex, edge, startVertex;
    cin >> vertex >> edge >> startVertex;
    vector<vector<int>> g = graph(vertex, edge);
    for(int i=1;i<=vertex;i++){
        sort(g[i].begin(), g[i].end(), compare);
    }


    visited.resize(vertex+1, 0);
    order.resize(vertex+1, 0);

    //DFS순서대로 출력하는 부분
    DFS(g, vertex, startVertex);

    for(int i=1;i<=vertex;i++){
        cout<<order[i]<<"\n";
    }
}