#include <bits/stdc++.h>
using namespace std;

int N;
int S[1000];
int cache[1001];

int Len(int idx,int last){
    if(idx>=N) return 0;
    int & res=cache[idx];
    if(res!=-1) return res;
    res=0;
    for(int i=idx;i<N;++i){
        if(last<S[i]){//만약 원소 선택이 가능하면
            res=max(res,1+Len(i+1,S[i]));//해당 원소를 선택했을때와 아닐떄 중 최대값을 비교
        }
    }
    return res;
}

int main() {
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=0;i<N;++i)cin>>S[i];
    cout<<Len(0,0);
}

/*
https://chanhuiseok.github.io/posts/algo-49/
*/