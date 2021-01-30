#include <string>
#include <queue>
#include <vector>

using namespace std;

pair<int,int> split(string s){
    pair<int,int> res;
    if(s[0]=='I')res=make_pair(0,stoi(s.substr(2)));
    else res=make_pair(1,stoi(s.substr(2)));
    return res;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> MxQ;
    priority_queue<int> MnQ;
    int ins=0;
    for(int i=0;i<operations.size();++i){
        pair<int,int> temp=split(operations[i]);
        if(temp.first){
            if(ins==0)continue; 
            ins--;
            if(temp.second==1)MxQ.pop();
            else MnQ.pop();
        }else{
            ins++;
            MxQ.push(temp.second);
            MnQ.push(-temp.second);
        }
        if(ins==0){
            while(!MxQ.empty())MxQ.pop();
            while(!MnQ.empty())MnQ.pop();
        }
    }
    if(ins==0) answer={0,0};
    else answer={MxQ.top(),-MnQ.top()};
    return answer;
}
/*
1.어차피 큐가 완전히 비는 경우가 아니면 한쪽만 빼도 된다.
우선순위큐가 비지 않았다면 양쪽 큐 중 하나만 빼는 식으로 계산하고,
큐가 완전히 비면 양 우선순위큐를 비워버린다.(오류 방지)
*/