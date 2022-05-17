#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=87654321;

int n, k;
int v[1000], w[1000];
int cache[1000][10001];
struct node{
    int x,y,dir;
};

int bag(int x, int W){
    if(x==k)return 0;
    int & res=cache[x][W];
    if(res!=-1)return res;
    res=0;
    if(W+w[x]<=n)return res=max(bag(x+1,W), v[x]+bag(x+1,W+w[x]));
    else return res=bag(x+1,W);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin>>n>>k;
    for(int i=0;i<k;++i)cin>>v[i]>>w[i];
    cout<<bag(0,0);
    return 0;
}

/*
1. 01 배낭문제이다. 배낭의 남은 무게와 더 넣을 과목만 주어진다면 이미 배낭 안에 들어간 것은 따질 필요가 없다.(부분 최적 구조)
2. bag(x, W) => 현재 배낭 무게가 W이고 x번째 선택중일 때, 배낭의 무게 내에서 가치의 최대값
bag(x,W)= max(bag(x+1,W),v[x]+(bag(x+1,w[x]+W))
*/
