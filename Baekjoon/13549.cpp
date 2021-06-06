#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int n,k;

int BFS(){
    queue<vector<int>> Q;
    Q.push({n,0});
    int res=987654321;
    int visited[200001];
    while(!Q.empty()){
        int current=Q.front()[0];
        int time=Q.front()[1];
        visited[current]=1;
        if(current==k)res=min(res,time);
        Q.pop();
        if(current*2<=k*2&&!visited[current*2])Q.push({current*2,time});
        if(!visited[current+1])Q.push({current+1,time+1});
        if(current>0&&!visited[current-1])Q.push({current-1,time+1});
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cout<<BFS();
    return 0;
}

/*
1.매 이동마다 x-1,x+1,2x중 하나를 택한다. 
동생의 위치에 도달했을 때 시간들 중 가장 작은 값을 취한다.
2.
그대로 두면 무한히 탐색을 하게 되므로, 특정 조치를 취해야 한다.
해당 칸을 방문했는지 확인하여 이미 방문한 노드는 무시한다.
최대 2*k까지만 배열을 만들어 확인한다.
*/