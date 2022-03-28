#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=INT_MAX;

int T;
int n,m;
int friends[10][10];//x,y가 친한지 확인
int visited[10];

int brute(){
    int target=-1;
    for(int i=0;i<n;++i)if(visited[i]==0){//조합이므로 순서를 고정해줘야 한다. 맨 앞의 원소를 매 순간 찾는다.
        target=i;break;
    }
    if(target==-1)return 1;//반드시 완료 가능한 케이스를 주므로 더 찾을 원소가 없다면 탐색이 끝났다는 뜻
    visited[target]=1;
    int res=0;
    for(int i=target+1;i<n;++i){
        if(visited[i]==0 && friends[target][i]==1){//아직 방문하지 않은 친구 중 친한 친구라면
            visited[i]=1;
            res+=brute();//방문 처리하에 재귀
            visited[i]=0;
        }
    }
    visited[target]=0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(friends,0,sizeof(friends));//매 테스트 케이스마다 배열 초기화
        memset(visited,0,sizeof(visited));
        for(int i=0;i<m;++i){
            int a,b; cin>>a>>b;
            friends[a][b]=friends[b][a]=1;//양쪽 모두가 친구여야 하므로 반대도 넣어야 함
        }
        cout<<brute()<<'\n';
    }
    return 0;
}

/*
브루트로 해결 가능한가? 10!, o
순서를 고려해야 하는가? 조합, x
완전 탐색 시 깊이 우선 탐색 -> visit 체크 필요
*/