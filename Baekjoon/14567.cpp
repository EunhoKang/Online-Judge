#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int graph[1001][1001];
int cache[1001];

int solve(int node){
    int & res=cache[node];
    if(res!=-1)return res;
    res=1;
    for(int i=1;i<=n;++i)if(graph[node][i])res=max(res,1+solve(i));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(graph,0,sizeof(graph));
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<m;++i){
        int a,b; cin>>a>>b;
        graph[b][a]=1;
    }
    for(int i=1;i<=n;++i)cout<<solve(i)<<" ";
    return 0;
}
/*
1.트리로 표현한다. 어떤 과목의 선수 과목을 자식 노드로 설정한다.
어떤 노드에서 한 리프까지의 최대 거리가 곧 이수에 필요한 과목 수이다.
다만 트리는 구현이 힘드니 방향 그래프로 대체한다.
2.탐색은 어느곳에서든 모든 노드를 탐색하면 된다. 탐색시 새로운 노드를 방문할 때 마다
DP를 시행한다.
3.함수:
solve(node)=node 과목의 수강에 필요한 최소 학기
점화식:
solve(node)=1+max(solve(leaf)...)
기저 사례:
자식 노드가 없다면->1 반환
----
원래는 위상정렬 문제이다.
https://velog.io/@kkoma2623/%EB%B0%B1%EC%A4%80-14567%EB%B2%88-%EC%84%A0%EC%88%98%EA%B3%BC%EB%AA%A9
*/