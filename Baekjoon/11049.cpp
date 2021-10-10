#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
int col[500];
int row[500];
ll cache[501][501];

ll Matrix(int s, int e){
    if(s==e)return 0;
    ll & res=cache[s][e];
    if(res!=-1)return res;
    res=INF;
    for(int i=s;i<e;++i){
        res=min(res,col[s]*row[i]*row[e]+Matrix(s,i)+Matrix(i+1,e));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>col[i]>>row[i];
    memset(cache,-1,sizeof(cache));
    cout<<Matrix(0,n-1);
    return 0;
}

/*
https://t-anb.tistory.com/10
D(s,e)=s부터 e까지 행렬곱을 진행했을때 최소 연산 횟수
D(s,e)=min(s-row*i-col*e-col + D(s,i) + D(i+1,e))
*/