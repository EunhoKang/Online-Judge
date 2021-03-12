#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
    vector<int> towers;
    cin>>N;
    for(int i=0;i<N;++i) {
        int tower;
        cin>>tower;
        towers.push_back(tower);
    }
    stack<vector<int>> sigs;
    int last=0;
    for(int i=0;i<N;++i){
        while(!sigs.empty() && sigs.top()[1]<towers[i]){
            sigs.pop();
        }
        if(!sigs.empty())cout<<sigs.top()[0]<<" ";
        else cout<<0<<" ";
        sigs.push({i+1,towers[i]});
    }
}

/*
1. 모든 탑은 자신의 오른쪽 탑으로 신호를 보낼 수 없다.
따라서 어떤 탑이 다른 탑으로 수신하는지 알려면 왼쪽의 탑만 보면 된다.
스택 사용.

2. 이 문제는 어떤 탑 뒤에 무슨 탑이 있던 상관이 없다는 점을 이용한다.
앞에서부터 스택에 차례대로 넣고, 
top보다 다음에 넣을 값이 크다면 앞의 값은 모두 필요가 없으므로 지운다.
이런 식으로 전부 지운 후 가장 위에 남는 탑이 비교 대상 탑이다.

https://mygumi.tistory.com/101
*/