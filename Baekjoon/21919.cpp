#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
int A[10000];
int pick[1000001];

void fillpick(){
    fill(pick,pick+1000001,-1);
    pick[1]=0;
    for(int i=2;i<=1000000;++i){
        if(pick[i]!=0){
            pick[i]=1;
            for(int j=2;j*i<=1000000;++j)pick[i*j]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>A[i];
    fillpick();
    
    ll res=1;
    for(int i=0;i<n;++i)if(pick[A[i]]==1){
        res*=A[i];
        pick[A[i]]=-1;
    }
    if(res==1)cout<<-1;
    else cout<<res;
    return 0;
}
/*
1. 소수들의 최소공배수 == 등장한 소수들의 종류별 곱
2. 1000000까지의 수에 10000개나 되는 대상을 검사해야 하므로 주먹구구식은 안된다.
에라토스테네스의 채를 사용하자.
3. long long 활용
*/