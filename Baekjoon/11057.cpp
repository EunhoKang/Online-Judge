#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int cache[10][1001]; 

int solution ( int previous_number, int number_left ) {
    if ( number_left == 0 ) return 1;
    int & result = cache[previous_number][number_left];
    if( result != -1 ) return result;
    else { 
        result = 0;
        for ( int i = previous_number; i < 10; ++i ) {
            result += solution( i, number_left - 1 );
            result %= 10007;
        }
        return result;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset( cache, -1, sizeof(cache) );
    int N;
    cin >> N;
    cout << solution ( 0, N );
    return 0;
}