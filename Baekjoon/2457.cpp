#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;
pair<int,int> flower[100000];

int cache[100000][13][32];

int water(int idx, int month, int day){
    if(idx==n){
        if(month*100+day>1130)return 0;
        else return INF;
    }
    int & res=cache[idx][month][day];
    if(res!=-1)return res;
    if(month*100+day>=flower[idx].first){
        res=min(1+water(idx+1,flower[idx].second/100,flower[idx].second%100),water(idx+1,month,day));
    }else{
        res=water(idx+1,month,day);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        flower[i]={a*100+b,c*100+d};
    };
    sort(flower,flower+n);
    memset(cache,-1,sizeof(cache));
    if(water(0,3,1)>=INF)cout<<0;
    else cout<<water(0,3,1);
    return 0;
}

/*
1. 모든 꽃을 대조해볼 경우 O(N^2)인데 N<=100000이므로 브루트 불가능.
꽃의 피는 시기를 기준으로 정렬했을 때, 
이전의 선택은 꽃이 피는 기간을 제외하면 이후의 선택에 영향을 주지 않는다.(최적 부분 구조)
꽃이 지는 날짜에 의해 다른 선택으로 같은 결과값이 나올 수 있으므로 DP 사용이 가능하다.
2. water(idx, month, day)=>현재 idx번째 꽃을 선택하고 month월 day일에 마지막 꽃이 질 때, 최소한으로 고를 수 있는 꽃의 수
water(idx, month, day)=min(1+water(idx+1,flower[idx].second/100,flower[idx].second%100),water(idx+1,month,day));
3. 192MB이므로 인덱스, 월, 일로 맞춰 나눠야 공간이 초과되지 않는다.

*/