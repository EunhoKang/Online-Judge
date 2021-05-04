#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll k;

int Solve(ll cnt){
    if(cnt==0)return 0;
    else{
        ll all=0;
        for(int i=0;i<100;++i){
            all=pow(2,i);
            if(cnt<all)break;
        }
        return !Solve(cnt-all/2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k;
    cout<<Solve(k-1);
    return 0;
}
/*
1.문자열이 각 시도에서 정확히 두배가 된다.
이 문자열이 유한하다고 가정했을 때 정확히 절반을 자르면 X와 X'로 나뉜다.
2.k가 주어졌을 때 k보다 작은 2^n중 n이 최대가 되는 값을 정하고,
이 값을 k에서 뺸 값은 항상 반대가 된다.
이 과정을 반복하다보면 필연적으로 인덱스가 0으로 도달하게 된다.
3. 1000=10^3=2^10, 10^18=2^60.
*/