#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,l,r;
int grid[50][50];
int visited[50][50];
vector<vector<int>> nodes;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int DFS(int y, int x){
    if(0<=x&&x<n&&0<=y&&y<n){
        int res=grid[y][x];
        if(!visited[y][x]){
            visited[y][x]=1;
            nodes.push_back({y,x});
            for(int i=0;i<4;++i){
                int delta=abs(grid[y][x]-grid[y+dir[i][0]][x+dir[i][1]]);
                if(l<=delta && delta<=r && !visited[y+dir[i][0]][x+dir[i][1]])res+=DFS(y+dir[i][0],x+dir[i][1]);
            }
        }
        return res;
    }
    return 0;
}

int routine(){
    int cnt=0;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int unite=DFS(i,j);
            if(nodes.size()!=0){
                unite/=nodes.size();
                if(nodes.size()>1)cnt++;
                for(vector<int> node : nodes)grid[node[0]][node[1]]=unite;
            }
            nodes.clear();
        }
    }
    if(cnt>0)return 0;
    else return 1;
}

int solve(){
    int cnt=0;
    while(true){
        int finish=routine();
        cnt++;
        if(finish)return cnt-1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>l>>r;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>grid[i][j];
    cout<<solve();
    return 0;
}

/*
1.인접국과 연쇄적으로 이어지므로 DFS. 더불어 정사각형 격자이므로 인접 배열 형식을 활용한다.
*/