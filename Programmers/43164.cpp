#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> V;
vector<vector<string>> E;

int DFS(string start,vector<int> used){
    V.push_back(start);
    int res=0;
    for(int i=0;i<E.size();++i){
        if(E[i][0]==start && !used[i]){
            used[i]=1;
            if(DFS(E[i][1],used)){
                return 1;
            }
            used[i]=0;
        }
    }
    if(V.size()==E.size()+1) return 1;
    V.pop_back();
    return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(),tickets.end());
    E=tickets;
    vector<int> used;
    for(int i=0;i<E.size();++i) used.push_back(0);
    DFS("ICN",used);
    answer=V;
    return answer;
}

int main(){
    solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}});
}

/*
1. 모든 티켓을 반드시 다 써야 하므로 남는 티켓이 발생하면 다시 진행한다.
2. 사이클이 발생할 수 있으므로 사용한 간선을 구분해야 한다.
*/