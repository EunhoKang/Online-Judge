#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=INT_MAX;

int T;
int n,m;
int grid[20][20];

static int block[4][3][2]={{{0,0},{1,0},{1,1}},{{0,0},{1,0},{0,1}},{{0,0},{0,1},{1,1}},{{0,0},{1,0},{1,-1}}};

int onBoard(int x, int y){//보드 위에 있는가?
    return 0<=x && x<n && 0<=y && y<m ? 1 : 0;
}

int canPut(int blockmode, int x, int y){//해당 위치에 놓을 수 있는가?
    for(int i=0;i<3;++i){
        int dx=x+block[blockmode][i][0];
        int dy=y+block[blockmode][i][1];
        if(onBoard(dx,dy)==0||grid[dx][dy]==1)return 0;
    }
    return 1;
}

int allFilled(){//모든 칸이 찼는가?
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]==0)return 0;
        }
    }
    return 1;
}

int brute(){
    int res=0;
    int x=-1;
    int y=-1;
    int flag=0;
    for(int i=0;i<n;++i){//왼쪽 최상단 칸 선택
        for(int j=0;j<m;++j){
            if(flag==1)break;
            if(grid[i][j]==0){
                x=i;y=j;flag=1;
            }
        }
        if(flag==1)break;
    }
    if(flag==0){//모든 칸이 방문됬거나 블럭을 놓을 수 없는 상태면 모든 칸이 찼는지 확인
        if(allFilled())return 1;
        else return 0;//다 찼으면 1, 차지 않았으면 0을 반환하고 종료
    }
    for(int i=0;i<4;++i){
        if(canPut(i,x,y)){//놓을 수 있으면
            for(int j=0;j<3;++j){//놓고 다음 블록 선택
                int dx=x+block[i][j][0];
                int dy=y+block[i][j][1];
                grid[dx][dy]=1;
            }
            res+=brute();
            for(int j=0;j<3;++j){//일일히 초기화
                int dx=x+block[i][j][0];
                int dy=y+block[i][j][1];
                grid[dx][dy]=0;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        memset(grid,0,sizeof(grid));
        cin>>n>>m;
        for(int i=0;i<n;++i){
            string str;cin>>str;
            for(int j=0;j<str.length();++j){
                if(str[j]=='#')grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
        cout<<brute()<<'\n';
    }
    return 0;
}

/*
1.흰칸의 수가 50을 넘지 않으므로 브루트포스로 먼저 시도 (개수 계산을 못하겠음)
2.블럭의 순서를 고려하지 않음로 조합으로 세야 함. 왼쪽 상단부터 블럭을 놓는다.
3.블럭의 기준은 위에서부터 채울때 블럭이 해당 위치를 채운다면 가질 수 있는 모든 블럭의 모양이 기준.
*/