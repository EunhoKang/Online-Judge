#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int N;
string S;
static char blocks[3]={'B','O','J'};
ll cache[1001][3];

ll dp(int n, int k){
    if(n==N-1)return 0;
    ll & res=cache[n][k];
    if(res!=-1)return res;
    res=INF;
    for(int i=n+1;i<N;++i){
        if(S[i]==blocks[(k+1)%3])res=min(res,(i-n)*(i-n)+dp(i,(k+1)%3));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>S;
    memset(cache,-1,sizeof(cache));
    ll res=dp(0,0);
    if(res>=INF)cout<<-1;
    else cout<<res;
    return 0;
}

/*
1.특정 위치에서 어떤 발판을 밟고 있는지만 알고 있다면 이전의 발판이나 에너지 소모는 이후의 계산에 영향 없음.
D(n,k)=>k상태인 n번칸에서 마지막 칸을 밟을 때까지 필요한 최대 에너지
D(n,k)=min(D(n+i,(k+1)%3)+i*2) (i=>1~N-n)
*/