#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> G[10001];
int t[10001];
int cache[10001];

vector<int> split(string s, char del){
    vector<int> res;
    string str;
    stringstream ss(s);
    while(getline(ss,str,del)){
        res.push_back(stoi(str));
    }
    return res;
}

int solve(int node){
    //cout<<i<<" "<<j<<" "<<'\n';
    if(G[node].size()==0) return t[node];
    int & res = cache[node];
    if(res!=-1)return res;
    res=0;
    for(int i=0;i<G[node].size();++i)res=max(res,t[node]+solve(G[node][i]));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i];
        int cnt; cin>>cnt;
        for(int j=0;j<cnt;++j){
            int temp; cin>>temp;
            G[i].push_back(temp);
        }
        G[0].push_back(i);
    }
    memset(cache,-1,sizeof(cache));
    cout<<solve(0)<<'\n';
    return 0;
}
/*
1.의존도에 따라 01 방향 그래프를 만들고
만들어진 그래프를 아무지점에서부터 DFS.
맨 끝에 도달했을때까지 걸린 시간을 모두 기록하여 가장 길게 걸리는 값이
전체 작업에 필요한 시간이다. 그보다 짧은 값은 무시되기 때문.
2.모든 노드를 시작점으로 잡고 탐색해봐야 하므로, 모든 노드와 연결된 노드 필요.
*/