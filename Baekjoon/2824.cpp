<<<<<<< HEAD
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long
const int MOD = 1000000000;

int N, M;
map<int, int> A, B;
vector<int> Prime;

bool visited[40000];

void MakeA(int a){
	for(auto now: Prime){
		if(a%now==0){
			A[now]++;
			MakeA(a/now);
			return;
		}
	}
	if(a!=1) A[a]++;
}
void MakeB(int a){
	for(auto now: Prime){
		if(a%now==0){
			B[now]++;
			MakeB(a/now);	
			return;
		}
	}
	if(a!=1) B[a]++;
}
int main(){

for (int i = 2; i < 40000; ++i){
	if(visited[i]) continue;
	Prime.push_back(i);
	for (int j = 2*i; j < 40000; j+=i) visited[j] = true;
}

bool Over = false;

cin >> N;
for (int i = 0; i < N; ++i){
	int num;
	cin >> num;
	MakeA(num);	
}

cin >> M;
for (int i = 0; i < M; ++i){
	int num;
	cin >> num;
	MakeB(num);
}

ll ans = 1LL;
for(auto iter: A){
	int now = iter.first;
	if(!B.count(now)) continue;
	int cnt = min(A[now],B[now]);
	while(cnt--){
		ans*=now;
		if(ans>MOD){
			Over=true;
			ans%=MOD;
		}
	}
}
if(Over){
	ans%=MOD;
	cout.width(9);
	cout.fill('0');
	cout << ans << '\n';
}
else cout << ans << '\n';
return 0;

/*
1. N,M을 소인수분해한다.
2. 소인수분해된 N,M을 정렬한 후 같은 수만 골라낸다.
<<<<<<< HEAD
맵핑으로 소인수분해를 해두면 편하게 표현이 가능하다.
3. 에라토스테네스의 채를 이용한다.
40000까지만 하는 이유는, 만약 이런식으로 진행할 경우 나머지가 남게 되는데,
40000까지 걸러낸 후 합성수 나머지의 최소값이 40001*40002로 대략 1600000000이다.
입력의 최대값인 1000000000 보다 크므로 나머지가 소수의 곱으로 표현될 일은 없다.
4.숫자가 선언된 정수형 범위를 넘어갈 수 있기 때문에 계속 10^9로 나눠
나머지만을 저장해야 한다.
또한 이렇게 표현된 값일 경우 뒷부분에 0이 추가되므로 유의한다.

https://mapocodingpark.blogspot.com/2020/01/BOJ-2824.html
*/
