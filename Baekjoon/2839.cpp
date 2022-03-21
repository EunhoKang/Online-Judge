#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int w;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>w;
	int n=0;
	for(int i=w/5;i>=0;--i){//5kg 계산
		int temp=(w-5*i)%3;//3kg 나눠떨어지는지 확인
		if(temp==0){
			n=i+(w-5*i)/3;
			break;
		}
	}
	if(n==0) n=-1;//나눠떨어지는 경우가 아예 없으면 -1
	cout<<n;
    return 0;
}

/*
가능한 한 많은 5kg 봉지를 들고가는게 무조건 이득이다.
최대한 많은 5kg 봉지를 빼보고 그 다음 3kg 봉지로 나누어떨어지는지 확인한다.
N=5000이 최악의 경우인데도 1000번만 확인해보면 되기 때문에 반드시 시간 안에 해결 가능하다.
*/
