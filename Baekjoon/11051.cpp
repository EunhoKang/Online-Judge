#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10007;
int cache[1001][1001];

int bino(int n, int k){
    if (n == 0 || k == 0 || n == k) return 1;
    int & res = cache[n][k];
    if (res != -1) return res;
    return res = (bino(n - 1, k - 1) % MOD + bino(n - 1, k) % MOD) % MOD;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(cache, -1, sizeof(cache));
    int N, K;
    cin >> N >> K;
    cout << bino(N, K);
}
