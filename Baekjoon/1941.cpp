#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=21000000;

int grid[5][5];
int picked[5][5];
int somun[5][5];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int OnBoard(int x, int y){
    if(0<=x && x<5 && 0<=y && y<5)return true;
    else return false;
}

int Pick7(int yun, int n){
    if(yun>3)return 0;
    if(n==7)return 1;
    int x=-1,y=-1;
    for(auto i : {0,1,2,3,4}){
        int flag=0;
        for(auto j : {0,1,2,3,4}){
            if(picked[i][j]==0){
                if(n!=0){
                    int flag2=0;
                    for(auto k : {0,1,2,3}){
                        if(OnBoard(i+dx[k],j+dy[k]) && somun[i+dx[k]][j+dy[k]]==1){
                            flag2=1;
                            break;
                        }
                    }
                    if(flag2==0)continue;
                }
                flag=1;
                x=i;
                y=j;
                break;
            }
        }
        if(flag==1)break;
    }
    if(x==-1)return 0;
    int res=0;
    picked[x][y]=1;
    somun[x][y]=1;
    res+=(grid[x][y]==0 ? Pick7(yun+1,n+1):Pick7(yun,n+1));
    somun[x][y]=0;
    res+=Pick7(yun,n);
    picked[x][y]=0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(auto i : {0,1,2,3,4}){
        string temp;
        cin>>temp;
        for(auto j : {0,1,2,3,4})grid[i][j]=(temp[j]=='S' ? 1 : 0);
    }
    cout<<Pick7(0,0);
    return 0;
}

/*
경우의 수는 25C7=480700
1. 좌측 상단부터 찾기
2. 이미 방문한 칸인지 확인
3. 인접한 칸이 있는지 확인
4. 7개일 경우 s가 4개 이상인지 확인
*/
