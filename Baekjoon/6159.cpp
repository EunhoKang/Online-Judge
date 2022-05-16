#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

int n,s;
int cow[20000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;++i)cin>>cow[i];
    int l=0,r=1;
    int res=0;
    sort(cow,cow+n);
    while(l<n-1){
        if(r>=n){
            l++;
            r=l+1;
        }else{
            if(cow[l]+cow[r]<=s){
                res++;
                r++;
            }else{
                l++;
                r=l+1;
            }
        }
    }
    cout<<res;
    return 0;
}

/*
1. O(N^2) 이므로 40억번 연산을 해야 한다. 브루트는 불가.
2. 정렬 후 투 포인터를 이용한다. 왼쪽 값은 고정시키고 오른쪽 값만 증가시키다가 크기가 넘어가면 왼쪽을 움직인다.
*/