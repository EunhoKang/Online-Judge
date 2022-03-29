#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
int grid[10][10];
int plusline[20];
int minusline[20];
int maxCount[2];

void BackTracking(int cnt, int odd){
    if(cnt>maxCount[odd]){//만약 더 많은 비숍을 두었다면 갱신한다.
        maxCount[odd]=cnt;
    }
    int tY=-1,tX=-1;
    for(int i=odd;i<2*n-1;i+=2){//좌측 최상단 중 가능한 칸에 비숍을 둔다.
        if(plusline[i]==0){//먼저 합 대각선을 기준으로 두고 하나씩 살펴본다.
            for(int j=0;j<i+1;++j){
                if(i-j<n && j<n){
                    if(grid[i-j][j]==1 && minusline[2*j-i+n-1]==0){
                        tY=i-j;tX=j;
                        break;
                    }
                }
            }
        }
        if(tY!=-1)break;
    }
    if(tY==-1)return;//더 찾을 노드가 없다면 해당 가지에서 최대의 비숏을 놓은 것이므로 종료.
    grid[tY][tX]=0;//문제에서 0이면 방문이 불가능하므로 평소의 visited 배열에서 약간 변형하였다.
    plusline[tY+tX]=1;
    minusline[tX-tY+n-1]=1;
    BackTracking(cnt+1,odd);//해당 위치에 비숍을 두거나
    plusline[tY+tX]=0;
    minusline[tX-tY+n-1]=0;
    BackTracking(cnt,odd);//두지 않고 방문 처리만 한다.
    grid[tY][tX]=1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>grid[i][j];
    BackTracking(0,0);//검은판
    BackTracking(0,1);//흰판
    cout<<maxCount[0]+maxCount[1];
    return 0;
}

/*
1.N퀸 문제와 빗스하지만 올릴 수 있는 최대 개수를 찾는 문제라 조금 다르다.
최악의 케이스인 N=10일때 모든 대각선을 고려하면 19!=121645100408832000로 절대 계산이 안되는 수준이 된다.
2.그런데 대각선만 고려하는 비숍의 특징을 보면, 체스판에서 가로, 세로로 붙어있는 칸들끼리는 영향을 줄 수 없다.
이를 활용하면 체스판을 검은색 판과 흰색 판 두 개의 덩어리로 분리할 수 있고, 이 둘을 따로 계산해 합치는 방식을 생각하면 경우의 수가 매우 줄어든다.
두 덩어리는 서로에게 아예 영향을 주지 못하는 독립 시행이기 때문이다.
경우의 수는 10!=3628800로 줄어들며 이제 완전탐색이 가능해진다.
3.각각의 칸에 놓는 경우는 조합이기 때문에 중복을 걸러내야 한다.
이를 위해 비숍의 위치를 정할 때 좌측 최상단부터 놓는 방식을 사용한다.
*/