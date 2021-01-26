#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> PQ;
    queue<pair<int,int>> Q;
    queue<int> ansQ;
    for(int i=0;i<priorities.size();++i){
        PQ.push(priorities[i]);
        Q.push(make_pair(priorities[i],i));
    }
    while(!PQ.empty()){
        if(Q.front().first==PQ.top()){
            PQ.pop();
            ansQ.push(Q.front().second);
        }else{
            Q.push(Q.front());
        }
        Q.pop();
    }
    int cnt=1;
    while(!ansQ.empty()){
        if(ansQ.front()==location){
            answer=cnt;
            break;
        }
        cnt++;
        ansQ.pop();
    }
    return answer;
}