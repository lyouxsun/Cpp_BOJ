/* 주의점
항상 for문의 범위를 i=0 ~ i<N까지로 해주었지만 이번 문제에서는 i=1~i<=N까지로 해주었다.
이 부분에서 i<=N이 아닌 i<N으로 설정하여 계속 오류가 났다.
앞으로 이런 경우에는 코드 맨 윗부분에 주의사항으로 적어두기!!!
*/
#include <iostream>
#include <vector>
using namespace std;
int vertexNum;
int visited[1010];
vector<vector<int>> arr;

void Graph(int vertexNum, int edgeNum);
void AddEdge(vector<vector<int>>& arr, int edge1, int edge2);
void DFS(vector<vector<int>>& arr, vector<int>& visited, int start);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int edgeNum;
    cin>>vertexNum>>edgeNum;
    Graph(vertexNum, edgeNum);
    /* 그래프 출력
    for(int i=1;i<=vertexNum;i++){
        for(int j=1;j<=vertexNum;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    vector<int> visited(vertexNum+1);   //정점방문여부 확인하는 배열 

    for(int i=1;i<=vertexNum;i++){
        if(visited[i]==0){
            DFS(arr, visited, i);
        }
    }
}

//그래프 만드는 함수
void Graph(int vertexNum, int edgeNum){
    arr.resize((vertexNum+1),vector<int>(vertexNum+1));     //그래프 배열
    int tmp1, tmp2;
    for(int i=0;i<edgeNum;i++){
        cin>>tmp1>>tmp2;
        AddEdge(arr, tmp1, tmp2);
    }
}

void AddEdge(vector<vector<int>>& arr, int edge1, int edge2){
    arr[edge1][edge2]=1;
    arr[edge2][edge1]=1;
}

//DFS함수
void DFS(vector<vector<int>>& arr, vector<int>& visited, int start){
    cout<<"> "<<start;
    visited[start]=1;
    for(int i=1;i<=vertexNum;i++){
        if(arr[start][i]==1 && visited[i]==0){
            DFS(arr, visited, i);
        }
    }
}