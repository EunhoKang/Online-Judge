#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=INT_MAX;

int T;
int n;
int cache[41][2];

int fibo(int k,int target){//아예 0이나 1을 몇번 호출하는지에 대해 dp를 진행한다.
    int & res=cache[k][target];
    if(res!=-1)return res; 
    if(k==0){
        return res=target==0?1:0;
    }else if(k==1){
        return res=target==1?1:0;
    }else{
        return res=fibo(k-1,target)+fibo(k-2,target);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    memset(cache,-1,sizeof(cache));
    while(T--){
        cin>>n;
        cout<<fibo(n,0)<<" "<<fibo(n,1)<<'\n';
    }
    return 0;
}

/*
1.기존 피보나치 문제는 dp로 치환하여 풀 수 있는 문제이다.
이 때 dp를 하는 과정에서 해당 캐시에 접근하는 횟수를 추가로 캐싱하면 문제를 풀 수 있다.
2.불리는 0과 1의 횟수는 생각보다 많은 부분을 실제 값을 구하는 것과 일치한다.
그 예시로 4번 피보나치를 부르는데 필요한 0,1의 수는 2,3번 피보나치 수들에서 그것들이 불리는 수를 더하면 된다.
3.범위가 작아 int 범위에서 연산이 가능하다.
*/