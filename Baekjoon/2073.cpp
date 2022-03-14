#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int d,p;
int L[351];
int C[351];
int cache[100001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>d>>p;
    for(int i=1;i<=p;++i)cin>>L[i]>>C[i];
    //memset(cache,-1,sizeof(cache));
    cache[0]=INF;
    for(int i=1;i<=p;i++){
        for(int j=d;j>=0;j--){
            if (j-L[i]>=0)
                cache[j]=max(cache[j],min(cache[j-L[i]],C[i]));
        }
    }
    cout<<cache[d];
    return 0;
}

/*
D(len,n)=n번째까지의 관들로 만들 수 있는 총 길이 len의 관의 최대 용량
매 선택 때마다 그 배관을 선택하는 경우와 선택하지 않는 경우를 비교한다.
배관 선택시 지금까지의 최소 용량과 해당 배관의 최소 용량 중 더 작은 것을 택한다.
D(len,n)=max(min(D(len-L[n],n-1),C[i]),D(len,n-1))

이때 n은 바로 전 내용만을 기억하면 되기 때문에,
슬라이딩 윈도 기법을 쓰면 윈도우의 길이가 2이므로 1차원 배열에 저장해도 된다.
즉 현재 값을 그대로 연산에 넣고 연산 결과를 다시 현재 배열에 넣어도 문제 없으므로,
n에 대한 공간 계산 자체가 필요없다.
마지막으로 길이가 0인 경우 파이프를 만들지 못한 것이므로,
반드시 다른쪽 파이프가 선택이 되어야 한다. 따라서 매우 큰 값으로 설정.
*/