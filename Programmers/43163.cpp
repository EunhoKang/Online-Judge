#include <string>
#include <vector>
#include <queue>

using namespace std;

int Linked(string a, string b){
    int res=1;
    for(int i=0;i<a.size();++i){
        if(a[i]!=b[i]){
            res--;
        }
    }
    if(res==0) return 1;
    else return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<vector<int>> Q;
    vector<string> E;
    int G[51][51];
    int visit[51];
    int N=words.size()+1;

    E.push_back(begin);
    for(int i=0;i<words.size();++i)E.push_back(words[i]);
    for(int i=0;i<N;++i){
        for(int j=0; j<E.size();++j){
            if(Linked(E[i],E[j])){
                G[i][j]=1;G[j][i]=1;
            }else {
                G[i][j]=0;G[j][i]=0;
            }
        }
        G[i][i]=0;
    }
    for(int i=0;i<N;++i)visit[i]=0;
    
    Q.push({0,0});
    int U; int L;
    while(!Q.empty()){
        U=Q.front()[0];
        L=Q.front()[1];
        Q.pop();
        if(words[U-1]==target) break;
        visit[U]=1;
        for(int V=0;V<N;++V)if(G[U][V] && !visit[V]) Q.push({V,L+1});
    }
    answer=L;
    if(words[U-1]!=target) answer=0;
    return answer;
}

/*
1. BFS는 반드시 깊이가 얕은 순서로 진행한다.
*/