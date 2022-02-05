#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
int A[1001];
int cache[1001][2];

int LBS(int index, int istop){
    if(index==n)return 0;
    int & res=cache[index][istop];
    if(res!=-1)return res;
    res=0;
    for(int i=index+1;i<=n;++i){
        if(istop==1){
            if(A[index]>A[i]){
                res=max(res,1+LBS(i,1));
            }
        }else{
            if(A[index]<A[i]){
                res=max(res,max(1+LBS(i,0),1+LBS(i,1)));
            }
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(cache,-1,sizeof(cache));
    for(int i=1;i<=n;++i){
        cin>>A[i];
    }
    cout<<LBS(0,0);
    return 0;
}
/*
1. 긴 수열에서 특정 수를 선택해나간다고 하자.
해당 선택 순서에서 수열이 이미 증가에서 감소로 돌아섰는지 여부를 알고 있다면,
이전에 어떤 선택을 했는지와 앞으로 가장 긴 수열을 얻기 위해 어떤 선택을 해야하는지는
관계성을 갖지 못하며, 특정 위치에서 같은 선택을 해야 하는 경우가 많이 발생한다.
-> DP
2.첫 시작 선택을 위해 -1번쨰 인덱스를 만들자.
*/