#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> Q;
    for(int i=0;i<scoville.size();++i){
        Q.push(-scoville[i]);
    }
    while(Q.size()>1 && Q.top()>-K){
        int a,b,c;
        a=Q.top();
        Q.pop();
        b=Q.top();
        Q.pop();
        c=a+b*2;
        Q.push(c);
        answer++;
    }
    if(Q.top()>-K) return -1;
    return answer;
}
/*
1.우선순위큐를 뒤집어 사용하기 위해 음수를 취한다.
*/