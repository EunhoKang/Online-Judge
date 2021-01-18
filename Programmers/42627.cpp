#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>> Q;
    priority_queue<pair<int,int>> PQ;
    for(int i=0;i<jobs.size();++i){
        Q.push(make_pair(-jobs[i][0],-jobs[i][1]));
    }
    int res=0;
    int cut=0;
    int t=0;
    while(!Q.empty() || !PQ.empty()){
        while(!Q.empty()&&Q.top().first==-t){
            PQ.push(make_pair(Q.top().second,Q.top().first));
            Q.pop();
        }
        if(!PQ.empty() && cut<=t){
            pair<int,int> temp=PQ.top();
            res+=(t-(-temp.second)+(-temp.first));
            cut=t+(-temp.first);
            PQ.pop();
        }
        ++t;
    }
    answer=res/jobs.size();
    return answer;
}