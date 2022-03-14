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
D(s,e)=s부터 e까지 행렬곱을 진행했을때 최소 연산 횟수
간단하게 모든 경우의 수를 시도해보면 알 수 있다. 
나머지 경우의 수는 이미 행렬 계산이 끝났다고 가정하고 마지막 연산을 한다고 생각해보자.
s==i || i+1==e 일 경우 0이 반환된다.
D(s,e)=min(s-row*i-col*e-col + D(s,i) + D(i+1,e))
처음부터 2^31-1까지 출력이 나온다고 했으니 long long을 쓴다.
*/