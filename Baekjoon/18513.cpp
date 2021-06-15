#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

const int MAX=100000000;
int n,k;
int spring[100000];
map<int,int> visited;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>spring[i];
    for(int i=0;i<n;++i)visited[spring[i]]=1;

    ll res=0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;++i)q.push(make_pair(spring[i], 0));
    while(!q.empty() && k>0){
        int target=q.front().first;
        int dt=q.front().second;
        q.pop();
        if(k>0 && visited.find(target-1)==visited.end()){
            visited[target-1]=1;
            k--;
            q.push(make_pair(target-1,dt+1));
            res+=dt+1;
        }
        if(k>0 && visited.find(target+1)==visited.end()){
            visited[target+1]=1;
            k--;
            q.push(make_pair(target+1,dt+1));
            res+=dt+1;
        }
    }
    cout<<res;
    return 0;
}

/*
1.기존 샘물 바로 옆칸이 비었으면, 안 지을 이유가 없다.
2.모든 샘의 양 옆이 꽉차면, 두칸 거리에 있는 곳이 비었을 떄 안 지을 이유가 없다.
3.해당 위치를 방문했는지만 저장해두면 계속해서 샘물 주변을 순회하며 집의 위치를 정할 수 있다.
4.범위가 넓으므로 map 사용.
---
https://hsdevelopment.tistory.com/521
1씩 범위가 증가->bfs
*/