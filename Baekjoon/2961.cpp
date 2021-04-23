#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sum=998877665544332211;
int n;
int s[10],b[10];

ll Calc(vector<int> pick){
    ll S=1,B=0;
    for(int i=0;i<pick.size();++i){
        S*=s[pick[i]];
        B+=b[pick[i]];
    }
    return abs(S-B);
}

void Pick(int cnt,int k,vector<int> picked,int start){
    if(cnt>=k){
        sum=min(sum,Calc(picked));
    }
    for(int i=start;i<n;++i){
        vector<int> temp=picked;
        temp.push_back(i);
        Pick(cnt+1,k,temp,i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(s,0,sizeof(s));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;++i)cin>>s[i]>>b[i];
    vector<int> pick={};
    for(int i=1;i<=n;++i)Pick(0,i,pick,0);
    cout<<sum;
    return 0;
}
/*
1.크기가 1000000000인 것을 곱해야 하므로 아예 long long 형으로 설정한다.
2.조합 뽑기이므로 순서를 고정해야 한다.
*/