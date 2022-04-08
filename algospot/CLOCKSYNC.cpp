#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

static int btn[10][16]={
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
    {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
    {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

int T;
int clocks[16];

int checkFinish(){
    for(int i=0;i<16;++i){//나머지로 계산
        if(clocks[i]%12!=0)return 0;
    }
    return 1;
}

int brute(int num){
    if(num>=10){//만약 답이 나왔으면 0, 아니면 매우 큰 값을 반환
        if(checkFinish()==1)return 0;
        else return INF;
    }
    int res=INF;
    for(int i=0;i<4;++i){
        res=min(res,brute(num+1)+i);
        for(int j=0;j<16;++j){//어차피 4번 누르면 원래대로 돌아가기 때문에 다시 되돌릴 필요가 없다.
            if(btn[num][j]==1)clocks[j]+=3;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        for(int i=0;i<16;++i)cin>>clocks[i];
        int answer=brute(0);
        if(answer>=INF)cout<<-1;
        else cout<<answer;
        cout<<'\n';
    }
    return 0;
}

/*
1.16개의 시계가 가질 수 있는 상태는 3,6,9,12시로 각 4개뿐. 
각 버튼은 4번 누르면 다시 원래대로 돌아온다. 따라서 각 버튼마다 4번씩 눌러보면서 모든 경우를 확인하면 된다.
버튼은 10개로 고정이므로 4^10==2^20=10^6==백만회. 브루트로 풀만한 문제이다.
2.정말 버튼 4번 누르고 백트래킹 돌리면서 가능한 경우의 수를 전부 찾으면 된다. 찾을때마다 누른 버튼의 횟수를 기억한다.
*/