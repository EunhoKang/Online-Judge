#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;

void PrintResult(int cnt,vector<int> visit, vector<int> pick){
    if(cnt>=m){
        for(int i=0;i<pick.size();++i)cout<<pick[i]<<" ";
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;++i){
        if(visit[i]) continue;
        visit[i]=1;
        vector<int> temp=pick;
        temp.push_back(i);
        PrintResult(cnt+1,visit,temp);
        visit[i]=0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<int> visit;
    for(int i=0;i<=n;++i)visit.push_back(0);
    PrintResult(0, visit, {});
    return 0;
}
/*
1.단순한 백트래킹 함수.
*/