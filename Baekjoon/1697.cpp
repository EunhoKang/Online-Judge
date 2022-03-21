#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

struct node{
    int t;
    int pos;
};

int str,des;
int visited[400002];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>str>>des;
    queue<node> q;
    q.push({0,str});//시작 노드 방문
    visited[str]=1;
    if(str==des){//시작점과 도착지 일치 시 바로 처리
        cout<<0;
        return 0;
    }
    while(!q.empty()){
        node nd=q.front();
        q.pop();
        if(nd.pos==des){//도착 시 즉시 break
            cout<<nd.t;
            break;
        }
        if(visited[nd.pos*2]==0 && nd.pos*2<=des*2){//두배를 넘어갈 이유는 없다.
            visited[nd.pos*2]=1;
            q.push({nd.t+1,nd.pos*2});
        }
        if(visited[nd.pos-1]==0 && nd.pos-1>=0){//0보다 작아지면 세그폴트가 나온다.
            visited[nd.pos-1]=1;
            q.push({nd.t+1,nd.pos-1});
        }
        if(visited[nd.pos+1]==0 && nd.pos+1<=des){//마찬가지로 도착지를 넘어갔는데 앞으로 갈 이유 없음.
            visited[nd.pos+1]=1;
            q.push({nd.t+1,nd.pos+1});
        }
    }
    return 0;
}

/*
1.특정 개체에 대해 주기적인 상태의 변화에서 최대/최소값 찾기는 BFS의 대표적 예시이다. 먼저 시도해본다.
1-1.노드의 값은 시간과 1차원 위치로 설정. 
이미 도착한 상태에서는 더 이상 움직일 필요가 없으므로 종료 조건은 동생 좌표*2인 지점이다.
1-2.한 노드에서 다른 노드로 움직이는 방법은 -1, +1, *2로 총 세가지이다.
일차원 배열을 통해 방문 처리가 가능하다. 굳이 더 느린 시간 안에 같은 곳에 도착할 이유는 없다.
1-3.최대 노드 방문 횟수가 곧 시간 복잡도가 된다. 최악의 경우 공간 내 모든 공간을 visit 하므로 O(2N)안에 해결 가능.
1-4.visit 공간을 넉넉히 잡아야 한다.
*/