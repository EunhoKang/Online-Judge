#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n;
int num[101];
int visited[101];
vector<int> res;

void solve(int start, int node, vector<int> s){
    if(visited[node])return;
    s.push_back(node);
    visited[node]=1;
    if(start==num[node])for(int i=0;i<s.size();++i)res.push_back(s[i]);
    solve(start,num[node],s);
    visited[node]=0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>num[i];
    for(int i=1;i<=n;++i)solve(i,i,{});
    int prev=-1;
    vector<int> answer;
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();++i){
        if(prev!=res[i])answer.push_back(res[i]);
        prev=res[i];
    }
    cout<<answer.size()<<'\n';
    for(int i=0;i<answer.size();++i)cout<<answer[i]<<'\n';
    return 0;
}

/*
1.한 원소의 값을 인덱스로 다시 탐색하면서 계속 탐색을 이어나간다.
이때 하나로 이어져 처음 시작점으로 돌아오는 경우를 탐색.
*/