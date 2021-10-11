#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
int children[201];
int cache[201];

int LIS(int last){
    if(last>n)return 0;
    int & res=cache[last];
    if(res!=-1)return res;
    res=0;
    for(int i=last+1;i<=n;++i){
        if(children[i]>children[last]){
            res=max(res,LIS(i)+1);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>children[i];
    memset(cache,-1,sizeof(cache));
    cout<<n-LIS(0);
    return 0;
}

/*
최장 부분 수열을 기준으로 나머지 아이들을 배치하면 된다.
맨 처음 숫자는 반드시 담아갈 수 있으므로 비교값을 작게 설정해야 한다.
*/