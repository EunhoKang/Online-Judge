#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
int happy[20];
int health[20];

int solution(int ith, int w){
    if(ith==n) return 0;//기저. 더 이상 인사가 가능한 사람이 없으면 재귀 종료
    int res=0;
    if(w-health[ith]>0){//체력이 되는 한에서 인사가 가능하면 둘 모두 탐색
        return max(happy[ith]+solution(ith+1,w-health[ith]),solution(ith+1,w));
    }else{//인사를 할 수 없는 상황이면 다음으로 넘어감.
        return solution(ith+1,w);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>health[i];
    for(int i=0;i<n;++i)cin>>happy[i];//입력 전부 기록.
    cout<<solution(0,100);
    return 0;
}

/*
n이 20 이하이므로 브루트포스로 해결 가능.
*/