#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=21000000;

int n;
int cache[100][100][100];
int MOD=10007;

int run(int a, int b,int idx){
    if(a==b)return 0;
    if(idx==n-1)return 1;
    int & res=cache[a][b][idx];
    if(res!=-1)return res;
    return res=(run(a,b,idx+1)%MOD+run(a+1,b,idx+1)%MOD+run(a,b+1,idx+1)%MOD+run(a+1,b+1,idx+1)%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(cache,-1,sizeof(cache));
    cout<<(run(1,0,1)%MOD+run(0,1,1)%MOD)%MOD;
    return 0;
}