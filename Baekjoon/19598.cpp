#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > t;
priority_queue<int> room;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for( int i = 0; i < n; ++i ){
        int a, b; cin >> a >> b;
        t.push( { a, b } );
    }
    room.push(0);
    while( !t.empty() ){
        if( t.top().first >= -room.top() ) {
            room.pop();
        }
        room.push( -t.top().second );
        t.pop();
    }
    cout << room.size();
    return 0;
}
/*
1. 대표적인 스케줄 문제로 그리디 알고리즘으로 풀면 된다.
2. 최대한 비는 시간이 없게끔 배치를 해야 한다.
각 회의 시작 시간과 해당 회의실의 회의가 끝나는 시간을 비교하여 차가 가장 작도록 한다.
3. 위에 해당하는 작업을 O(n)이 아닌 O(logn)안에 하려면 우선순위큐를 써야 한다.
4. 비어있는 방은 큐에서 빼고 업데이트된 시간을 넣어 다시 큐에 넣는다.
*/
