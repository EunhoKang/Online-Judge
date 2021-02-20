#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<int> PQ;
    priority_queue<int> MPQ;
    queue<int> Q;
    for(int i=0;i<n;++i){
        int command; cin>>command;
        if(command!=0){
            if(command>0) PQ.push(-command);
            else MPQ.push(command);
        }else{
            int prt;
            if(PQ.size()>0){
                if(MPQ.size()>0){
                    if(PQ.top()<=MPQ.top()){
                        prt=MPQ.top();
                        MPQ.pop();
                    }else{
                        prt=-PQ.top();
                        PQ.pop();
                    }
                }else{
                    prt=-PQ.top();
                    PQ.pop();
                }
            }else if(MPQ.size()>0){
                prt=MPQ.top();
                MPQ.pop();
            }else{
                prt=0;
            }
            Q.push(prt);
        }
    }
    while(!Q.empty()) {
        cout<<Q.front()<<'\n';
        Q.pop();
    }
}

/*
힙->우선순위 큐.
입력삭제연산이 많을수록 유리하다.
*/