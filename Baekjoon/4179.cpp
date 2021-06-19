#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,m;
int grid[1000][1000];
int visited[1000][1000];
vector<int> start;
const int dy[4]={0,0,1,-1};
const int dx[4]={1,-1,0,0};
struct node{
    int y;
    int x;
    int t;
};
vector<node> fire;

int BFS(){
    queue<node> q;
    queue<node> f;
    for(int i=0;i<fire.size();++i)f.push(fire[i]);
    int prevT=-1;
    q.push({start[0],start[1],0});
    visited[q.front().y][q.front().x]=1;
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int t=q.front().t;
        q.pop();
        if(t>prevT){
            while(!f.empty()){
                int fy=f.front().y;
                int fx=f.front().x;
                int ft=f.front().t;
                if(ft>t)break;
                f.pop();
                for(int i=0;i<4;++i){
                    if(0<=fy+dy[i]&&fy+dy[i]<n&&0<=fx+dx[i]&&fx+dx[i]<m
                    &&grid[fy+dy[i]][fx+dx[i]]==0){
                        grid[fy+dy[i]][fx+dx[i]]=-1;
                        f.push({fy+dy[i],fx+dx[i],t+1});
                    }
                }
            }
        }
        prevT=t;
        if(y==0 || y==n-1 || x==0 || x==m-1)return t+1;
        for(int i=0;i<4;++i){
            if(0<=y+dy[i]&&y+dy[i]<n&&0<=x+dx[i]&&x+dx[i]<m
            &&visited[y+dy[i]][x+dx[i]]==0
            &&grid[y+dy[i]][x+dx[i]]==0){
                visited[y+dy[i]][x+dx[i]]=1;
                q.push({y+dy[i],x+dx[i],t+1});
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        string s; cin>>s;
        for(int j=0;j<m;++j){
            if(s[j]=='#')grid[i][j]=1;
            else if(s[j]=='J'){
                grid[i][j]=0;
                start={i,j};
            }
            else if(s[j]=='F'){
                grid[i][j]=-1;
                fire.push_back({i,j,0});
            }
            else grid[i][j]=0;
        }
    }
    int res=BFS();
    if(res==-1)cout<<"IMPOSSIBLE";
    else cout<<res;
    return 0;
}

/*
1.불이 나더라도 한번 왔던 곳을 다시 올 필요는 없으며,
서로 다른 시간에 같은 장소를 오려면 긴 쪽은 최단거리가 될 수 없다.
따라서 캐싱은 좌표만.
2.불꽃은 이미 있는 곳은 빼고 새로 탄 곳만 저장한다.
불이 붙을 예정인 곳도 피해야 한다.
----
BFS 문제는 실수와의 전쟁이다. 하나라도 실수 나오면 큰일난다.

*/