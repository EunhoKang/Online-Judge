#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int grid[1000][1000];
int cache[1001][1001][3];//0:↙,1:↓,2:↘,3:startpoint

int solve(int i, int j, int dir){
    if(j<0 || j>=m) return 987654321;
    if(i==n)return 0;
    int & res=cache[i][j][dir];
    if(res!=-1)return res;
    res=grid[i][j];
    if(dir==0)res+=min(solve(i+1,j,1),solve(i+1,j+1,2));
    else if(dir==1)res+=min(solve(i+1,j-1,0),solve(i+1,j+1,2));
    else if(dir==2)res+=min(solve(i+1,j-1,0),solve(i+1,j,1));
    else res+=min(solve(i+1,j-1,0),min(solve(i+1,j,1),solve(i+1,j+1,2)));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>grid[i][j];
    memset(cache,-1,sizeof(cache));
    int res=987654321;
    for(int j=0;j<m;++j)res=min(res,solve(0,j,3));
    cout<<res;
    return 0;
}
/*
1.필요한 인자는 현재 좌표와 이전에 움직인 방향까지 세개이다.
2.함수:
solve(x,y,dir)=현재 위치가 x,y이고 이전 움직임이 dir 일때, 
앞으로 선택들을 통해 도착점까지 드는 최소 비용.
---
함수에 직접 인수를 넣어 재귀로 짜지 않고도 해결이 가능하다.
점화식을 제대로 짜는 연습을 하자.
https://github.com/devxb/JJUNalgo/blob/master/17485%20%EC%A7%84%EC%9A%B0%EC%9D%98%20%EB%8B%AC%20%EC%97%AC%ED%96%89%20(Large)/main.cpp
*/