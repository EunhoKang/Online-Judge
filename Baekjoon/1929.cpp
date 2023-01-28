#include <iostream>

using namespace std;

bool PrimeArray[1000001];

void Eratos(int n) {
    if (n <= 1) return;
	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;
	for (int i = 2; i * i <= n; i++)
		if (PrimeArray[i])
			for (int j = i * 2 ; j <= n; j += i)
				PrimeArray[j] = false;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int M, N;
    cin >> M >> N;
    Eratos(N);
    for (int i = M; i <= N; ++i)
        if (PrimeArray[i]) cout << i << '\n';
}
