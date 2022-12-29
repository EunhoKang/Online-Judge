#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

map<string, int> integers;
int N, K;
string cards[10]; 
bool visited[10];
int ans = 0;

void countInteger( int k, string current) {
    if(k == K) {
        if(integers.find(current) == integers.end()){
            integers[current] = 1;
            ans++;
        }
        return;
    }
    for(int i = 0; i < N; ++i) {
        if(!visited[i]) {
            visited[i] = true;
            countInteger( k + 1, current + cards[i] );
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> cards[i];
    countInteger( 0, "" );
    cout << ans;
    return 0;
}

/*
1.중복 순열 전체 구현이 필요하다.
2.set을 써서 같은 숫자는 걸러내야 한다.
*/