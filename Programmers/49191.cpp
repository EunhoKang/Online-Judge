#include <string>
#include <vector>
#include <math.h>

using namespace std;
const int INF=1000000;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int dist[101][101];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dist[i][j]=(i==j ? 0:INF);
    for(int i=0;i<results.size();++i)
        dist[results[i][0]][results[i][1]]=1;
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    for(int i=1;i<=n;++i){
        int lost=0;
        for(int j=1;j<=n;++j){
            if(!(dist[i][j]<INF || dist[j][i]<INF)) {
                lost=1;
                break;
            }
        }
        if(!lost)answer++;
    }
    return answer;
}

/*
1. https://nsios.tistory.com/117?category=899499
간선이 어떤 경로로든 이어져 있다면 순위를 알 수 있다
반대로 이어져 있지 않다면(거리가 무한) 순위를 알 수 없다
자기 자신을 제외한 모든 노드와 연결될 경우만 순위를 알 수 있다.
어떤 경로로든 이어져 있으면 통과가 가능하므로 최단경로 알고리즘을 활용하면 된다.

모든 정점에 대해 업데이트를 해야 하므로,
한 정점에 대해서만 최단 거리를 구하는 다익스트라보다는
모든 정점에 대해 최단 거리를 구하는 플로이드 워샬을 쓰는게 더 빠르다.
벨만 포드 알고리즘은 다익스트라처럼 한 정점에 대해 구하지만 음수 가중치 적용 가능.
*/