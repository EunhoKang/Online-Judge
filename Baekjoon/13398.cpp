#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
int num[100000];
int cache[100000][2][2];

int getsum(int idx, int start, int jump){
    if(idx==n){
        if(start==0)return -INF;
        else return 0;
    }
    int & res=cache[idx][start][jump];
    if(res!=-1)return res;
    if(start==0){
        res=max(num[idx]+getsum(idx+1,1,jump),getsum(idx+1,0,jump));
    }else{
        if(jump==0){
            res=max(num[idx]+getsum(idx+1,start,0),getsum(idx+1,start,1));
        }else{
            res=num[idx]+getsum(idx+1,start,1);
        }
        res=max(res,0);
    }
    return res;
}

vector<int> split(string st, char del);

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>num[i];
    memset(cache,-1,sizeof(cache));
    cout<<getsum(0,0,0);
    return 0;
}