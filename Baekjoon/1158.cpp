#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    queue<int> Q;
    for(int i=1;i<=n;++i) Q.push(i);
    cout<<'<';
    while(!Q.empty()){
        for(int i=0;i<k-1;++i){
            int tp=Q.front();
            Q.pop();
            Q.push(tp);
        }
        cout<<Q.front();
        Q.pop();
        if(!Q.empty())cout<<", ";
    }
    cout<<'>';
}

/*
1. 원형으로 돌아가므로 큐를 사용해 지나간 순번을 다시 큐 뒤로 넣는다.
*/