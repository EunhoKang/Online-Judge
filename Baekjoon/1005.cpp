#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T,n,k;
int develop[1001];
vector<int> G[1001];
int answer;
int cache[1001];

int solution(int idx) {
    if(G[idx].size()==0) return develop[idx];
    int & res=cache[idx];
    if(res!=-1) return res;
    for(int i=0;i<G[idx].size();++i)
        res=max(res,develop[idx]+solution(G[idx][i]));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    for(int I=0;I<T;++I){
        memset(cache,-1,sizeof(cache));
        memset(develop,0,sizeof(develop));
        cin>>n>>k;
        for(int i=1;i<=n;++i){
            G[i]={};
            cin>>develop[i];
        }
        for(int i=0;i<k;++i){
            int a,b;
            cin>>a>>b;
            G[b].push_back(a);
        }
        cin>>answer;
        cout<<solution(answer)<<'\n';
    }
    return 0;
}
/*
1.각각의 건설 순서를 트리로 만들어 리프까지 걸리는 경로들 중 가장 긴 것이 최소 시간이다.
*/