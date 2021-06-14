#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,m;
vector<int> graph[2001];
int visited[2000];

int DFS(int node,int depth){
    if(depth==5)return 1;
    for(int i=0;i<graph[node].size();++i){
        if(!visited[graph[node][i]]){
            visited[graph[node][i]]=1;
            if(DFS(graph[node][i],depth+1))return 1;
            visited[graph[node][i]]=0;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;++i)graph[2000].push_back(i);
    cout<<DFS(2000,0);
    return 0;
}

/*
1.모든 정점에서 탐색해보면서 깊이 4까지 내려가는지 확인한다.
*/