#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int arr[1000001];
    int res[1000001];
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    stack<int> S;
    for(int i=n-1;i>=0;--i){
        if(S.empty()){
            res[i]=-1;
        }else{
            if(S.top()>arr[i]){
                res[i]=S.top();
            }else{
                while(!S.empty()&&S.top()<=arr[i]){
                    S.pop();
                }
                if(S.empty()) res[i]=-1;
                else res[i]=S.top();
            }
        }
        S.push(arr[i]);
    }
    for(int i=0;i<n;++i){
        cout<<res[i]<<" ";
    }
    return 0;
}

/*
1.오른쪽에서부터 거꾸로 판별하면 이미 판별이 끝난 오큰수를 다시 판별하지 않아도 된다.
2.각 값을 오른쪽부터 스택에 넣는다.
만약 스택의 top보다 넣으려는 값이 작으면 오큰수를 구하고 넣고, 아닐경우 자신보다 큰 수가 나올 때까지 pop
사이에 낀 값은 저장할 필요가 없다.
*/