#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n,m;
int grid[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        string s;
        cin>>s;
        for(int j=1;j<=m;++j){
            grid[i][j]=s[j-1]-'0';
        }
    }
    int answer=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]!=0){
                grid[i][j]=min(min(grid[i-1][j],grid[i][j-1]),grid[i-1][j-1])+1;
                answer=max(grid[i][j],answer);
            }
        }
    }
    cout<<answer*answer;
    return 0;
}

/*
D(i,j)=i,j에서 왼쪽 위 공간에 생길 수 있는 가장 큰 정사각형 변 길이
만약 자신, 왼쪽, 왼쪽위, 위가 모두 1이라면
D(i,j)=min(D(i-1,j),D(i-1,j-1),D(i,j-1))+1
그외엔
D(i,j)=max(D(i-1,j),D(i-1,j-1),D(i,j-1))

이런 종류의 문제는 반복적 동적 계획법으로 푸는 게 더 좋다.
*/