#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int n;
int prime[4000001];
vector<int> primes;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    memset(prime,-1,sizeof(prime));
    for(int i=2;i<=n;++i){
        if(prime[i]!=-1)continue;
        prime[i]=1;
        for(int j=2;j*i<=n;++j){
            prime[i*j]=0;
        }
    }
    for(int i=2;i<=n;++i){
        if(prime[i]==1)primes.push_back(i);
    }
    int st=primes.size()-1;
    int ed=primes.size()-1;
    int res=primes[primes.size()-1];
    int cnt=0;
    while(st>=0){
        if(res==n){
            cnt++;
            st--;
            res+=primes[st];
        }else if(res<n){
            st--;
            res+=primes[st];
        }else {
            res-=primes[ed];
            ed--;
        }
    }
    cout<<cnt;
}

/*
1.아리스토텔레스의 채로 걸러낸다
2.투 포인터를 이용해 연속합 표현. 위에서부터 시작하면 갯수를 맞출 수 있다.
*/
