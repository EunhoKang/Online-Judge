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
1. 왼쪽에서 오른쪽으로 쓸고가면서 검사를 해보자. 
이미 하나의 탑에 닿았으면 그 탑보다 낮은 탑들은 더 이상 고려할 필요가 없다.
-> 스택 구조 활용
*/