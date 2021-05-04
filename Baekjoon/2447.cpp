#include <bits/stdc++.h>
using namespace std;
#define ll long long

int k;

char Solve(int x,int y,int cnt){
    if(cnt==1){
        return (x==1&&y==1)?' ':'*';
    }
    else{
        cnt/=3;
        if(cnt>x){
            if(cnt>y)return Solve(x,y,cnt);
            else if(cnt<=y&&y<cnt*2)return Solve(x,y-cnt,cnt);
            else return Solve(x,y-cnt*2,cnt);
        }else if(cnt<=x&&x<cnt*2){
            if(cnt>y)return Solve(x-cnt,y,cnt);
            else if(cnt<=y&&y<cnt*2)return ' ';
            else return Solve(x-cnt,y-cnt*2,cnt);
        }else{
            if(cnt>y)return Solve(x-cnt*2,y,cnt);
            else if(cnt<=y&&y<cnt*2)return Solve(x-cnt*2,y-cnt,cnt);
            else return Solve(x-cnt*2,y-cnt*2,cnt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k;
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            cout<<Solve(i,j,k);
        }
        cout<<'\n';
    }
    return 0;
}
/*
1.
1)n=3일때
->1,1일때만 점 생략
2)n=9
->1,1/1,4/1,7/4,1/4,4/4,7/7,1/7,4/7,7/3,3/3,4/3,5/4,3/4,5/5,3/5,4/5,5

2.전체를 기준으로 9분할 했을때 가로세로 모두 중앙이면 무조건 찍지 않고,
아닐 경우 분할된 조각을 기준으로 해당 작업을 반복한다.
분할된 조각의 길이가 1이 되면 종료. 

*/