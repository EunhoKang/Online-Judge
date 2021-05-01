#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int ans[80];

bool IsGood(int cnt){
    for(int start=0;start<cnt-1;++start){
        for(int end=start+1;end<cnt;++end){
            int flag=true;
            for(int i=0;i<end-start+1;++i){
                if(start+1>cnt || end+1+i>cnt || ans[start+i]!=ans[end+1+i]) {
                    flag=false;
                    break;
                }
            }
            if(flag)return false;
        }
    }
    return true;
}

bool Answer(int cnt,int last){
    if(cnt==n) return IsGood(cnt);
    else{
        for(int i=1;i<=3;++i){
            if(last==i)continue;
            ans[cnt]=i;
            if(IsGood(cnt)){
                if(Answer(cnt+1,i))return true;
            }
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    Answer(0,0);
    for(int i=0;i<n;++i)cout<<ans[i];
    return 0;
}
/*
1.그리디로 풀려고 해도 이전의 패턴이 현재 패턴에 영향을 주므로 쓸 수 없다.
n<=80이므로 완전탐색으로 해결해보자.
가장 빠른 값을 뽑으면 되므로 최악의 경우는 상정하지 않아도 된다.
2.2^80가지의 조합을 만들어야 하므로, 가지치기가 반드시 필요하다.
문자열을 만드는 사이에 계속 좋은수열인지 검사한다.
-----
인덱스 문제는 항상 고려해야 한다. 
인덱스를 더할 떄는 out of range를 반드시 확인한다.
*/