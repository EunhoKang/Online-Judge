#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int T,a,b;
static vector<int> mod[10]={{0},{1},{2,4,8,6},{3,9,7,1},{4,6},{5},{6},{7,9,3,1},{8,4,2,6},{9,1}};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>a>>b;
        int temp=mod[a%10][(b-1)%mod[a%10].size()];
        if(temp==0)cout<<10<<'\n';
        else cout<<temp<<'\n';
    }
    return 0;
}

/*
10에 대한 나머지만 구하면 되므로 문제가 쉬워진다.
일의 자리 수에 대해서는 1~9까지의 경우의 수를 나눠 구하고,
십의 자리수는 일의 자리 연산에 영향이 없으므로 무시한다.
마침 제한 조건이 1~99이므로 난이도는 더 쉬워진다.
나머지 그룹은 1승부터 시작이므로 b의 값을 조금 건드려서 맞춰줘야 한다.
*/