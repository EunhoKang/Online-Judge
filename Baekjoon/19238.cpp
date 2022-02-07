#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,m,L;
int grid[20][20];
int A[20000],B[20000];
int startx,starty;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>L;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>grid[i][j];
            if(grid[i][j]==1){
                grid[i][j]=INF;
            }
        }
    }
    cin>>startx>>starty;
    for(int i=0;i<m;++i){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        grid[a-1][b-1]=i+1;
        grid[c-1][d-1]=-(i+1);
    }
    int isFindingPerson=1;
    while(L>0){
        queue<pair<int,int>> q;
        int visited[20][20];
        q.push({startx,starty});
        int dL=0;
        int isFindDef=0;
        while(!q.empty()){
            if(dL>L){
                //
            }
            pair<int,int> current=q.front();
            q.pop();
            visited[current.first][current.second]=1;
            if(isFindingPerson){
                if(0<grid[current.first][current.second] && grid[current.first][current.second]<=m){
                    //if()
                    startx=current.first;
                    starty=current.second;
                    L-=dL;
                    break;
                }
            }else{
                if(0>grid[current.first][current.second] && grid[current.first][current.second]>=-m){
                    startx=current.first;
                    starty=current.second;
                    L+=dL;
                    break;
                }
            }
            if(!isFindDef){}
            for(int i=0;i<4;++i){
                if(visited[current.first+dx[i]][current.second+dy[i]]==0 && grid[current.first+dx[i]][current.second+dy[i]]!=INF){
                    q.push({current.first+dx[i],current.second+dy[i]});
                }
            }
            dL++;
        }
    }
    return 0;
}
/*
1. 최단거리의 손님을 찾는다. 손님이 남아있지 않다면 성공, 손님이 남아있으나 찾을 수 없다면 실패.
2. 최단거리의 손님을 목적지까지 최단 거리로 운송한다. 목적지로 갈수 없거나 연료보다 이동거리가 크면 실패.
3. 2번 과정에서 이동한 거리의 두배만큼 연료가 찬다. 1번으로 돌아간다.
4. https://yabmoons.tistory.com/497
*/