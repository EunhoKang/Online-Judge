#include <iostream>

using namespace std;

bool PrimeArray[1000001];

int N, a, b;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        cout << lcm(a, b) <<'\n';
    }
    return 0;
}
