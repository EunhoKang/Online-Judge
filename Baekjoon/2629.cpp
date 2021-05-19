#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int w[30];
int question[10];
int cache[15001][30];

int solution(int weight, int cnt,int q) {
    if(weight==q)return 1;
    if(cnt==n) return 0;
    int & res=cache[weight][cnt]; 
    if(res!=-1) return res;
    return res=solution(abs(weight-w[cnt]),cnt+1,q)||solution(weight,cnt+1,q)||solution(weight+w[cnt],cnt+1,q);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>w[i];
    cin>>m;
    for(int i=0;i<m;++i)cin>>question[i];
    for(int i=0;i<m;++i){
        memset(cache,-1,sizeof(cache));
        if(solution(0,0,question[i]))cout<<"Y ";
        else cout<<"N ";
    }
    return 0;
}
/*
1.변형된 01배낭문제이다. 
각 단계에서 무게를 더하거나 빼거나 0을 더하면 된다.
현재 무게와 선택할 추의 인덱스만 안다면 
이전의 선택은 이후의 선택에 영향을 미치지 않는다.
2.가장 먼저 구슬을 왼쪽 저울에 넣는다. 
이후부터 차례대로 추를 왼쪽에 놓을 것인지 오른쪽에 놓을 것인지 정한다.
각 단계마다 저울이 수평을 이루며 하나 이상의 추 혹은 구슬이 놓였으면 구슬 측정 가능.
3.
solution(w,cnt)=현재 무게가 w이고 cnt번째 추를 선택중일 경우,
w가 구슬의 무게와 일치할 수 있는가?
solution(w,cnt)=solution(w-s[cnt],cnt+1)||solution(w+s[cnt],cnt+1)||solution(w,cnt+1)
w==question return true;
*/