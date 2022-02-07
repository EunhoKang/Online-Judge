#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int N;
int n,m;
int A[20000],B[20000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    while(N--){
        fill(A,A+20000,0);
        fill(B,B+20000,0);
        cin>>n>>m;
        for(int i=0;i<n;++i)cin>>A[i];
        for(int i=0;i<m;++i)cin>>B[i];
        sort(A,A+n);
        sort(B,B+m);
        int point=0;
        int res=0;
        for(int i=0;i<n;++i){
            for(int j=point;j<=m;++j){
                if(j==m || A[i]<=B[j]){
                    point=j;
                    res+=point;
                    break;
                }
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
/*
1. 정렬된 수열에서 원래 사용하던 정보를 재활용하면 더 금방 끝나지 않을까
2. 포인터를 이용한 비교법으로 O(M)만큼만 비교하도록 했다.
*/