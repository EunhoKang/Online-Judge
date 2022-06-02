#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=21000000;

int m,n;
int rest[5001];
vector<int> vertex[5001];
int cache[5001];

int climb(int cur){
    int & res=cache[cur];
    if(res!=-1)return res;
    res=1;
    for(auto next : vertex[cur])res=max(res,(rest[cur]<rest[next] ? 1+climb(next) : 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>rest[i];
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    for(int i=1;i<=n;++i)cout<<climb(i)<<'\n';
    return 0;
}

/*
1.특정 위치에서 이전의 선택은 이후의 결과에 영향x -> DP

*/