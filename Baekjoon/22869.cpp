#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,k;
int A[5001];
int cache[5001];

int DP(int idx){
    if(idx==n-1)return 1;
    int & res=cache[idx];
    if(res!=-1)return res;
    res=0;
    for(int i=idx+1;i<=n;++i){
        if((i-idx)*(1+abs(A[i]-A[idx]))<=k){
            res=DP(i);
            if(res)return res;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill(cache,cache+5001,-1);
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>A[i];
    if(DP(0))cout<<"YES";
    else cout<<"NO";
    return 0;
}
/*
1. A : 높이, i : 너비로 계산
2. 건너갈 수 있는지 없는지만 판별하면 된다.
특정 칸에 도착한 순간부터 이전의 진행 상황과 관계 없이 항상 같은 답이 나오므로 DP로 접근
단일 변수이며 5000개만 저장하면 된다.
*/