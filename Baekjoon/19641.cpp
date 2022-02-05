#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
vector<int> graph[100001];
pair<int,int> lr[100001];
int root;
int cnt=0;

void order(int prev, int v){
    int f,s;
    f=++cnt;
    for(int i=0;i<graph[v].size();++i){
        if(graph[v][i]==prev)continue;
        order(v,graph[v][i]);
    }
    s=++cnt;
    lr[v]={f,s};
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        int temp,v;
        cin>>temp;
        while(cin>>v){
            if(v==-1)break;
            graph[temp].push_back(v);
        }
        sort(graph[temp].begin(),graph[temp].end());
    }
    cin>>root;
    for(int i=1;i<=n;++i){
        lr[i]={-1,-1};
    }
    order(0,root);
    for(int i=1;i<=n;++i){
        cout<<i<<" "<<lr[i].first<<" "<<lr[i].second<<'\n';
    }
    return 0;
}
/*
1. 루트의 left/right는 n의 값에 따라 고정된다.
2. dfs로 탐색하면 left->right로 순서대로 값을 얻을 수 있다.
*/