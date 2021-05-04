#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,x,y;

int Solve(int cnt,int x, int y){
    if(cnt==0)return 0;
    else{
        if(x<pow(2,cnt-1)){
            if(y<pow(2,cnt-1)) return Solve(cnt-1,x,y);
            else return pow(2,2*cnt-2)+Solve(cnt-1, x, y-pow(2,cnt-1));
        }else{
            if(y<pow(2,cnt-1)) return 2*pow(2,2*cnt-2)+Solve(cnt-1,x-pow(2,cnt-1),y);
            else return 3*pow(2,2*cnt-2)+Solve(cnt-1, x-pow(2,cnt-1), y-pow(2,cnt-1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>x>>y;
    cout<<Solve(n,x,y);
    return 0;
}
/*
1.2^15*2^15는 10억이 넘는다. 직접 세는 건 불가능하다.
마찬가지로 저 많은 양을 배열에 넣는 것도 불가능하다.
2.4개 구역으로 분할했을 때, 길이 2^n인 이중배열에서
좌측 상단 구역의 한 원소는 우측 상단 구역의 비슷한 원소보다 
2^2n-2 만큼 차이가 난다. 
이 차이만큼을 더한 후 cnt-1인 구간에 대해 같은 연산을 반복한다.
이때 인덱스는 절반이 된 정사각형에 맞춰줘야 하므로 적절히 빼준다.
최소 단위가 될 경우(cnt==0) 0을 반환한다.
*/