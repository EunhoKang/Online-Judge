#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=INT_MAX;

int T;
int n,m;
int _friend[45][2];
int visited[10];
int isfriend[10][10];

int cnt(){
    int target=-1;
    for(int i=0;i<n;++i){
        if(visited[i]==0){
            target=i;
            break;
        }
    }
    if(target==-1)return 1;
    //cout<<"t:"<<target<<'\n';
    int res=0;
    visited[target]=1;
    for(int i=0;i<n;++i){
        if(visited[i]==0 && isfriend[target][i]==1){
            visited[i]=1;
            res+=cnt();
            visited[i]=0;
        }
    }
    visited[target]=0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(visited,0,sizeof(visited));
        memset(isfriend,0,sizeof(isfriend));
        for(int i=0;i<m;++i){
            cin>>_friend[i][0]>>_friend[i][1];
            isfriend[_friend[i][0]][_friend[i][1]]=isfriend[_friend[i][1]][_friend[i][0]]=1;
        }
        cout<<cnt()<<'\n';
    }
    return 0;
}

/*
*/