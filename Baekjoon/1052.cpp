#include <iostream>
#include <math.h>
using namespace std;

int n,k;

int Solve(int n, int k){
    int ans=n;
    while(1){
        int N=ans;
        int cnt=0;
        while(N>0){
            if(N%2==1) cnt++;
            N/=2;
        }
        if(cnt<=k) return ans-n;
        else ans++;
    }
}

int main(){
    cin>>n>>k;
    cout<<Solve(n,k);
}

/*
1.https://qgqg264.tistory.com/57
*/