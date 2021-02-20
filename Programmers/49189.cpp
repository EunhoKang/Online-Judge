#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<vector<int>> Q;
    int visit[20001];
    vector<int> G[20001];

    for(int i=0;i<edge.size();++i){
        G[edge[i][1]].push_back(edge[i][0]);
        G[edge[i][0]].push_back(edge[i][1]);
    }

    for(int i=1;i<=n;++i)visit[i]=0;
    
    Q.push({1,0});
    int U; int L=0;visit[1]=1;
    while(!Q.empty()){
        U=Q.front()[0];
        if(L<Q.front()[1]) answer=Q.size();
        L=Q.front()[1];
        Q.pop();
        for(int V=0;V<G[U].size();++V){
            if(!visit[G[U][V]]){
                Q.push({G[U][V],L+1});
                visit[G[U][V]]=1;
            }
        }
    }
    
    return answer;
}

/*
1. BFS는 시작점에서부터 거리가 같은 노드를 연속으로 탐색한다.
2. 무향 그래프임을 고려한다.
3. 정점 방문시 이미 방문했던 정점을 여러번 방문이 가능하므로 처리해준다.
4. 그래프를 구현할 때는 반드시 모든 장점을 방문할 때는 이중배열,
그렇지 않은 경우에는 배열 리스트를 활용한다.
*/