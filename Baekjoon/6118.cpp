#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,m;
vector<int> graph[20001];
int bestcnt;
vector<int> ans;
int visited[20001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bestcnt=0;
    
    queue<pair<int,int>> q;
    int bestdepth=0;
    q.push({1,0}); 
    visited[1]=1;
    while(!q.empty()){
        pair<int,int> idx=q.front();
        q.pop();
        bool isEnd=1;
        for(int i=0;i<graph[idx.first].size();++i){
            if(!visited[graph[idx.first][i]]){
                isEnd=0;
                q.push({graph[idx.first][i],idx.second+1});
                visited[graph[idx.first][i]]=1;
            }
        }
        if(isEnd){
            if(bestdepth==idx.second)ans.push_back(idx.first);
            else if(bestdepth<idx.second){
                ans.clear();
                ans.push_back(idx.first);
                bestdepth=idx.second;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans[0]<<" "<<bestdepth<<" "<<ans.size();
    return 0;
}
/*
1. 노드 사이 거리 -> bfs
*/