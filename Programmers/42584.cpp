#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> Q;
    int res=-1;
    int i;
    for(i=0;i<prices.size();++i){answer.push_back(0);}
    for(int i=0;i<prices.size();++i){
        while(!Q.empty() && prices[Q.top()]>prices[i]){
            answer[Q.top()]=i-Q.top();
            Q.pop();
        }
        Q.push(i);
        res=prices[i];
    }
    while(!Q.empty()){
        answer[Q.top()]=i-1-Q.top();
        Q.pop();
    }
    return answer;
}

/*
1.반복문에서 더 이상 pop 할게 없을 때도 예외처리해야한다.
*/