#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> G[501];
    int visit[501];
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int cnt=0;
    queue<pair<int,int>> Q;
    Q.push({1,0}); visit[1]=1;
    while(!Q.empty() && Q.front().second<3){
        int U=Q.front().first;
        int L=Q.front().second;
        if(0<L && L<3) cnt++;
        Q.pop();
        for(int V=0;V<G[U].size();++V){
            if(visit[G[U][V]])continue;
            visit[G[U][V]]=1;
            Q.push({G[U][V],L+1});
        }
        
    }

    cout<<cnt;
}

/*
깊이 2까지만 BFS
*/