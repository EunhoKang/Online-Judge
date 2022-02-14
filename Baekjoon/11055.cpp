#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
int A[1001];
int cache[1001];

int lis(int cnt){
    if(cnt>n)return 0;
    int & res=cache[cnt];
    if(res!=-1)return res;
    res=A[cnt];
    int temp=0;
    for(int i=cnt+1;i<=n;++i){
        if(A[cnt]<A[i])temp=max(temp,lis(i));
    }
    return res+=temp;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    fill(cache,cache+1001,-1);
    for(int i=1;i<=n;++i)cin>>A[i];
    cout<<lis(0);
    return 0;
}
/*
1. 기존 lis에서 살짝 변형
*/