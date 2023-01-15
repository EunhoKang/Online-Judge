#include <bits/stdc++.h>
using namespace std;

int N, C;
vector< vector< int > > minerals_x[100001];
vector< vector< int > > minerals_y[100001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> C;
    for(int i = 0; i < N; ++i ) {
        int a, b, c;
        cin >> a >> b >> c;
        minerals_x[a].push_back( { b, c } );
        minerals_y[b].push_back( { a, c } );
    }
    long long result = 0;
    int x, y, cnt;
    long long value;
    x = 100000;
    y = 1;
    cnt = 0;
    value = 0;
    while( 0 <= x && y < 100001 ) {
        if( cnt <= C ) {
            for( int i = 0; i < minerals_y[y].size(); ++i ){
                if( minerals_y[y][i][0] <= x ) {
                    value += minerals_y[y][i][1];
                    cnt++;
                }
            }
            y++;
        }
        else {
            for( int i = 0; i < minerals_x[x].size(); ++i ){
                if( minerals_x[x][i][0] < y ) {
                    value -= minerals_x[x][i][1];
                    cnt--;
                }
            }
            x--;
        }
        if( cnt <= C ) result = max( result, value );
    }
    cout << result;
    return 0;
}

/*
1. N이 최대 오십만인데 이 안에서 C개로 된 조합을 구하는 문제라 완전탐색은 불가능.
2. x,y에 대해 범위 자체를 구하여 계산하는 방식으로 계산한다.
x의 값을 최대로, y의 값을 최소로 둔 상태로 진행하는데,
범위 안의 원소 수가 기준보다 적다면 y를 증가시키고,
범위 안의 원소 수가 기준보다 많다면 x를 감소시킨다.
정답의 형태는 x, y가 둘다 크거나 작은 상황이 없기 때문에 이렇게 하면 많은 케이스를 예외로 처리할 수 있다.
3. 수많은 원소에 대해 대응하기 위해 배열이나 리스트 형태의 vector를 사용한다.
4. https://geniusjo-story.tistory.com/628
*/