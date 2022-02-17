#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,m,k,x;
vector<int> graph[300001];
int visited[300001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>x;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    queue<pair<int,int>> q;
    q.push({x,0});
    visited[x]=1;
    vector<int> ans;
    while(!q.empty()){
        pair<int,int> temp=q.front();
        q.pop();
        if(temp.second<k){
            for(int i=0;i<graph[temp.first].size();++i){
                if(visited[graph[temp.first][i]]==0){
                    visited[graph[temp.first][i]]=1;
                    q.push({graph[temp.first][i],temp.second+1});
                }
            }
        }else{
            ans.push_back(temp.first);
        }
    }
    if(ans.size()==0){
        cout<<-1;
        return 0;
    }
    sort(ans.begin(),ans.end());
    int last=-1;
    for(int v : ans){
        if(last==v)continue;
        cout<<v<<'\n';
        last=v;
    }
    return 0;
}
/*
1. 0/1 너비우선탐색.
*/