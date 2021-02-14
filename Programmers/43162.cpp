#include <string>
#include <vector>

using namespace std;

vector<vector<int>> com;
int visit[200];
int N;

int AllFound(){
    for(int i=0;i<N;++i)if(!visit[i]) return 0;
    return 1;
}

void DFS(int start){
    visit[start]=1;
    for(int i=0;i<N;++i){
        if(visit[i]) continue;
        if(com[start][i]){
            DFS(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    com=computers; N=n;
    for(int i=0;i<n;++i) visit[i]=0;
    while(!AllFound()){
        ++answer;
        for(int i=0;i<N;++i){
            if(!visit[i]){
                DFS(i);
                break;
            }
        }
    }
    return answer;
}
//모든 정점을 방문할때까지 DFS 한번당 1씩 카운트해주면 된다.