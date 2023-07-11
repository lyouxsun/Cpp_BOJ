#include <iostream>
#include <vector>

using namespace std;
static int vertex, edge;
static vector<int> visited;
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

void DFS(vector<vector<int>>& v, int start){
    //cout<<"start:"<<start<<" depth:"<<depth<<'\n';
    if(depth>=5) {
        return;
    }
    
    for(int i=0;i<v[start].size();i++){
        int next = *(v[start].begin()+i);
        if(!visited[next]){
            visited[next]=1;
            depth++;
            DFS(v, next);
        } 
        if(depth>=5){
            return;
        }   
    }
    //탐색하지 않은 노드가 남아있을 때에만 depth--;
    //모두 다 탐색했으면 returnn depth;
    for(int i=0;i<vertex;i++){
        if(!visited[i]) {
            //cout<<"방문하지 않은 노드:"<<i<<'\n';
            //cout<<"--------------------------------------------\n";
            depth--;
            return;
        }
        visited[i]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>vertex>>edge;
    vector<vector<int>> g = graph(vertex, edge);

    for(int i=0;i<vertex;i++){
        vector<int> tmp(vertex, 0);
        visited.swap(tmp);
        visited[i]=1;
        depth=1;
        DFS(g, i);
        //cout<<"depth:"<<depth<<'\n';
        if(depth>=5){
            cout<<"1";
            break;
        }
    }
    if(depth<5){
        cout<<"0";
    }
}