#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
int grid[20][20];
int res=INF;
vector<int> start;
vector<int> link;

int calculate(){
    int gap=0;
    for(int i=0;i<start.size();++i){
        for(int j=0;j<start.size();++j){
            gap+=grid[start[i]][start[j]];
        }
    }
    for(int i=0;i<link.size();++i){
        for(int j=0;j<link.size();++j){
            gap-=grid[link[i]][link[j]];
        }
    }
    return abs(gap);
}

void MakeTeam(int cnt){
    if(cnt>=n){
        res=min(calculate(),res);
        return;
    }
    start.push_back(cnt);
    MakeTeam(cnt+1);
    start.pop_back();
    link.push_back(cnt);
    MakeTeam(cnt+1);
    link.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>grid[i][j];
    MakeTeam(0);
    cout<<res;
    return 0;
}

/*
n=20이므로 2^20<10000000, 모든 조합을 만들어 세면 된다.
*/