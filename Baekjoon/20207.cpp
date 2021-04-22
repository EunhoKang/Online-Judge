#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a[0]==b[0]) return (a[1]-a[0])>(b[1]-b[0]);
    else return a[0]<b[0];
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> sc;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        sc.push_back({a,b});
    }
    sort(sc.begin(),sc.end(),compare);
    int sum[400];
    for(int i=0;i<399;++i)sum[i]=0;
    int w=0;
    int h=0;
    int res=0;
    int st=0;
    int ed=0;
    for(int i=0;i<n;++i){
        for(int j=sc[i][0];j<=sc[i][1];++j){
            sum[j]++;
        }
    }
    for(int i=1;i<399;++i){
        if(sum[i]==0){
            res+=(ed-st+1)*h;
            h=0;
        }else{
            if(sum[i-1]==0)st=i;
            ed=i;
            if(sum[i]>h)h=sum[i];
        }
    }
    cout<<res;
    return 0;
}
/*
1.문제 조건을 잘 읽자. 예제에 없는 조건도 존재할 수 있다.
2.최대 높이와 최대 가로 길이만 알면 되므로 각 스케줄마다 지정된 날짜 배열에 숫자만 늘려줘도 된다.
*/