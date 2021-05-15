#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int grid[500][500];
int cache[500][500];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int solve(int i, int j, int last){
    //cout<<i<<" "<<j<<" "<<'\n';
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    if(last<=grid[i][j]) return 0;
    if(i==n-1 && j==m-1) return 1;
    int & res = cache[i][j];
    if(res!=-1)return res;
    res=0;
    for(int k=0;k<4;++k)res+=solve(i+dx[k],j+dy[k],grid[i][j]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>grid[i][j];
    memset(cache,-1,sizeof(cache));
    cout<<solve(0,0,987654321)<<'\n';
    return 0;
}
/*
1.한번 지나간 길은 어차피 지나갈 수 없다. 한 지점에서 오른쪽 끝으로 가는 방법은 이전에 이동한 칸과 관계없이 일정하므로 좌표를 기준으로 캐싱.
solve(x,y)=(x,y)에 있을 때 우측 끝까지 가는 방법의 수
solve(x,y)=solve(x+1,y)+solve(x-1,y)+solve(x,y+1)+solve(x,y-1)
x<0 || x>=n || y<0 || y>=m return 0
*/