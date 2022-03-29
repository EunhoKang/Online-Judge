#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gridc[40];//x+y 대각선, 캐싱 크기는 아무렇게나
int gridd[40];//x-y 대각선
int gridy[14];
int ans = 0;
int n;

void dfs(int cnt) {
    if (cnt == n) {//모든 퀸을 놓는 경우를 센다.
        ans++;
        return;
    }
    for (int i=0; i<n; i++) {//여기선 가로줄을 cnt로 센다.
        if (gridy[i]==0 && gridc[i+cnt]==0 && gridd[i-cnt+14]==0) {
            gridy[i]=1;
            gridc[i+cnt]=1;
            gridd[i-cnt+14]=1;//0이하의 인덱스면 안되므로 예외처리를 한다.
            dfs(cnt+1);
            gridy[i]=0;
            gridc[i+cnt]=0;
            gridd[i-cnt+14]=0;
        }
    }
}

int main() {
    cin>>n;
    dfs(0);
    cout<<ans;
    return 0;
}

/*
1.간단히 생각해봤을 때 N개의 퀸을 놓는 것은 가로 세로만 고려했을 때 각 줄에 하나의 퀸을 놓는 행위이므로,
O(N!)에 끝나는 작업이다. N이 최대 14이므로 14!=87178291200, 실행 시간이 10초이고 대각선까지 고려하면 완전탐색을 시도할 만하다.
2.모든 퀸은 하나의 가로줄에 하나만 있어야 되므로 가로줄마다 하나씩 놓는 식으로 재귀문을 짠다.
또한 각각의 대각선은 모든 원소의 x,y의 합과 차가 서로 같으므로 이를 이용해 방문 처리를 한다.
*/