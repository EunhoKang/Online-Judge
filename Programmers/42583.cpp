#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> Q;
    vector<int> pos;
    vector<int> isOnBridge;
    for(int i=0;i<truck_weights.size();++i){
        Q.push(truck_weights[i]);
        pos.push_back(0);
        isOnBridge.push_back(0);
    }
    int t=0;
    int W=0;
    while(!Q.empty() || W!=0){
        if(Q.size()>0 && W+Q.front()<=weight){
            W+=Q.front();
            isOnBridge[truck_weights.size()-Q.size()]=1;
            Q.pop();
        }
        for(int i=0;i<pos.size();++i){
            if(isOnBridge[i]){
                pos[i]++;
                if(pos[i]>=bridge_length){
                    isOnBridge[i]=0;
                    W-=truck_weights[i];
                }
            }
        }
        t++;
    }
    answer=t+1;
    return answer;
}