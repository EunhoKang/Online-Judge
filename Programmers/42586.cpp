#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;
    vector<bool> isFin;
    for(int i=0;i<progresses.size();++i){
        Q.push(i);
        isFin.push_back(0);
    }
    while(!Q.empty()){
        for(int i=0;i<progresses.size();++i){
            progresses[i]+=speeds[i];
            if(progresses[i]>=100) isFin[i]=1;
        }
        int cnt=0;
        while(!Q.empty()){
            if(isFin[Q.front()]){
                Q.pop();
                cnt++;
            }else{
                break;
            }
        }
        if(cnt>0)answer.push_back(cnt);
    }
    return answer;
}