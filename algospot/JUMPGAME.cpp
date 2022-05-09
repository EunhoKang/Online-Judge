#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

int T;
int n;
int grid[100][100];
int cache[101][101];

int CanGo(int x, int y){
    if(0>x || x>=n || 0>y || y>=n )return 0;
    if(x==n-1 && y==n-1) return 1;
    int & res=cache[x][y];
    if(res!=-1)return res;
    return res=(CanGo(x+grid[x][y],y) || CanGo(x,y+grid[x][y])); 
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        memset(cache, -1, sizeof(cache));
        cin>>n;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>grid[i][j];
        cout<<((CanGo(0,0)==1) ? "YES" : "NO")<<'\n';
    }
    return 0;
}

/*
1. 최악의 경우 둘 중 하나 선택이므로 O(2^N)이 된다. 동적계획법으로 풀어보자.
2. CanGo(x,y) => x,y에 있을 때 맨 끝 칸에 도달할 수 있을지 알아보는 함수
CanGo(x,y) = CanGo(x+h,y) || CanGo(x,y+h)
기저 조건 : (x,y)가 맨 끝 칸이면 true 반환, x,y 중 하나라도 범위를 벗어나면 false 반환
3. 여러 칸에 대해 조사한다면 분명 같은 칸에 대해 복수의 방문이 이루어질 수 있으므로 동적계획법 유효.
*/
