#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int stat[11][11];
int pick[11];
int res=0;

int Solve(int cnt,int sum){
    if(cnt==11){
        res=max(res,sum);
        return 0;
    }
    else{
        for(int i=0;i<11;++i){
            if(stat[cnt][i]==0 || pick[i]==1)continue;
            pick[i]=1;
            Solve(cnt+1,stat[cnt][i]+sum);
            pick[i]=0;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int I=0;I<n;++I){
        res=0;
        memset(pick,0,sizeof(pick));
        for(int i=0;i<11;++i)for(int j=0;j<11;++j)cin>>stat[i][j];
        cout<<Solve(0,0)<<'\n';
    }
    return 0;
}
/*
1.일단 0인 경우 아예 배치가 불가능하고 항상 하나 이상의 올바른 포지셔닝이 가능하다.
---
실수 목록:
1.res 초기화 안함
2.pick 초기화 안함
3.괜히 배열에 직접 포문으로 0 넣다가 이전에 지워진 것도 같이 복원됨

똑같은 실수하면 옥상에서 뛰어내리는걸로
*/