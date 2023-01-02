#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int graph[16][16];
int cache[16][1<<16];
int n;

int findPath( int current, int bitmask ) {
    if( !bitmask ) 
        if( graph[current][0] != 0 )
            return graph[current][0];
        else   
            return INF;
    int & result = cache[current][bitmask];
    if( result != -1 ) return result;
    result = INF;
    for( int i = 1; i < n; ++i ) 
        if( ( bitmask & ( 1 << i ) && graph[current][i] != 0 ) ) 
            result = min( result, graph[current][i] + findPath( i, bitmask & ~( 1 << i ) ) );
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset( cache, -1, sizeof(cache) );
    cin >> n;
    for( int i = 0; i < n; ++i ) for ( int j = 0; j < n; ++j ) cin >> graph[i][j];
    cout << findPath( 0, ( 1 << n ) - 2 );
    return 0;
}


/*
1.완전 탐색으로는 16! = 2.092279e+13. 1억을 한참 넘으므로 제한 시간 1초 내 해결 불가능하다.

2.동적 계획법으로 상태를 캐싱해도 int 범위를 넘어갈 뿐 아니라 메모리 제한에 걸리게 된다.
외판원 순회는 현재 위치와 지금까지 방문 기록이 필요하기 때문에
4byte * 16 * 16!를 할 경우 제한 조건인 128MB를 한참 넘게 된다.

3.비트필드를 이용해 최적화한다. 이 경우 2^16 - 1 = 65535로 메모리 공간을 줄일 수 있다.
4byte * 16 * 65535 = 4128768 byte 이므로 제한 메모리 안에서 해결 가능.

4.0번 위치는 시작점으로 두고 순회. 모든 장소를 방문하면 현재 위치에서 0번 위치로 돌아온다.
모든 비트필드를 켜두고 방문할 때마다 끈다. 모든 비트가 꺼지면 0이 되므로 쉽게 걸러낼 수 있다.
또한 문제에서 거리가 0인 경우는 갈 수 없는 경우라고 명시했으므로 이 역시 걸러내야 한다.
*/