#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
int prefer[400][5];
int grid[20][20];
int student[400];
int res=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n*n;++i){
        cin>>prefer[i][0]>>prefer[i][1]>>prefer[i][2]>>prefer[i][3]>>prefer[i][4];
    }
    grid[1][1]=prefer[0][0];
    student[0]=prefer[0][0];
    for(int i=1;i<n*n;++i){
        int bx=0;
        int by=0;
        int friendly=0;
        int empty=0;
        for(int x=0;x<n;++x){
            for(int y=0;y<n;++y){
                if(grid[x][y]!=0)continue;
                int tempempty=0;
                int tempfriendly=0;
                for(int k=0;k<4;++k){
                    if(0<=x+dx[k] && x+dx[k]<n && 0<=y+dy[k] && y+dy[k]<n){
                        if(grid[x+dx[k]][y+dy[k]]==0)tempempty++;
                        else {
                            for(int l=1;l<5;++l){
                                if(grid[x+dx[k]][y+dy[k]]==prefer[i][l])tempfriendly++;
                            }
                        }
                    }
                }
                if(tempfriendly>friendly){
                    bx=x;
                    by=y;
                    friendly=tempfriendly;
                    empty=tempempty;
                }else if(tempfriendly==friendly && tempempty>empty){
                    bx=x;
                    by=y;
                    friendly=tempfriendly;
                    empty=tempempty;
                }
            }
        }
        grid[bx][by]=prefer[i][0];
        student[bx*n+by]=i;
    }
    for(int x=0;x<n;++x){
        for(int y=0;y<n;++y){
            int tempfriendly=0;
            if(grid[x][y]!=0){
                for(int k=0;k<4;++k){
                    if(0<=x+dx[k] && x+dx[k]<n && 0<=y+dy[k] && y+dy[k]<n){
                        for(int l=1;l<5;++l){
                            if(grid[x+dx[k]][y+dy[k]]==prefer[student[x*n+y]][l])tempfriendly++;
                        }
                    }
                }
                res+=(tempfriendly==0 ? 0 : pow(10,tempfriendly-1));
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}