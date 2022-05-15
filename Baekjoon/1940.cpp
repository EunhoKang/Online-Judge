#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

int N,M;
int resources[15000];


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;++i)cin>>resources[i];
    sort(resources,resources+N);
    int hi, lo, mid, found;
    int res=0;
    for(int i=0;i<N;++i){
        hi=N-1;
        lo=i+1;
        mid=(hi+lo)/2;
        found=0;
        while(lo<=hi){
            mid=(hi+lo)/2;
            if(resources[mid]+resources[i]>M)hi=mid-1;
            else if(resources[mid]+resources[i]<M)lo=mid+1;
            else{
                res++;
                break;
            }
        }
    }
    cout<<res;
    return 0;
}