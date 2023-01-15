#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int cache[1<<13][20][10][13];
int n, m, c;
int items[13];

int stealBiz( int visited, int W, int packedBag, int bizCnt ) {
    if( visited + 1 == ( 1 << n ) ) return bizCnt;
    int & result = cache[visited][W][packedBag][bizCnt];
    if( result != -1 ) return result;
    result = 0;
    for( int current = 0; current < n; ++current ) {
        if( !( visited & ( 1 << current ) ) ) {
            int pickedMask = visited | ( 1 << current );
            if( c >= items[current] )
                if( W >= items[current] ) 
                    result = max( result, stealBiz( pickedMask, W - items[current], packedBag, bizCnt + 1) );
                else if( packedBag < m )
                    result = max( result, stealBiz( pickedMask, c - items[current], packedBag + 1, bizCnt + 1 ) );
            result = max( result, stealBiz( pickedMask, W, packedBag, bizCnt ) );   
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset( cache, -1, sizeof(cache) );
    cin >> n >> m >> c;
    for( int i = 0; i < n; ++i ) cin >> items[i];
    cout << stealBiz( 0, c, 1, 0 );
    return 0;
}

/*
1. 완전 탐색시 O((M+1)^N) 의 시간복잡도이므로 범위 안에서 1억을 무조건 넘긴다. 브루트포스는 불가능
2. 01 배낭 문제와 유사하므로, 동적 계획법을 적용해본다.
3. 배낭이 서로 구분되지 않음을 이용해, 앞에서부터 배낭을 채우는 식으로 한다.
현재 채우고 있는 배낭의 무게만 입력하고 다 차면 새로운 가방을 꺼낸다. 즉, 무게를 0으로 만든다.
4. 공간복잡도는 13 * 20 * 10 * 2^13로 대략 10^9 정도이므로 128MB 안에 충분히 계산 가능하다.
5. 넣는 순서도 고려해야 하므로 마스크를 두개 쓴다. 하나는 뽑는 순서, 하나는 뽑은 실제 원소들.
*/