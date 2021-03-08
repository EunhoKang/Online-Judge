#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

string s;
vector<p> bra;
vector<string> ans;

void MakeS(int n,vector<int> select){
    if(n>=bra.size()) {
        string res;
        string tmp = s;
        for(int i=0; i<n; i++){
			if(select[i]) tmp[bra[i].x] = tmp[bra[i].y] = '.';
		}
        for(auto i : tmp) if(i != '.') res += i;
        ans.push_back(res);
        return;
    }
    MakeS(n+1,select);
    select[n]=1;
    MakeS(n+1,select);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;

	stack<int> stk;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '(') stk.push(i);
		else if(s[i] == ')'){
			bra.emplace_back(stk.top(), i);
			stk.pop();
		}
	}
    MakeS(0,{0,0,0,0,0,0,0,0,0,0});
	sort(ans.begin(), ans.end());
    if(ans[0]!=s) cout << ans[0] << "\n";
	for(int i=1; i<ans.size(); i++){
		if(ans[i-1] != ans[i] && ans[i]!=s) cout << ans[i] << "\n";
	}
}
/*
1. 문자열의 문자를 차례대로 큐에 집어넣는다.
2. 미리 괄호 위치를 기억해둔다.
3. 괄호 갯수 제한이 있으므로 가능하다.
4. 0/1 배낭문제를 응용해 제거할 괄호를 재귀적으로 선택하고 문자열을 생성한다.

https://justicehui.github.io/coci/2018/06/06/BOJ2800/
*/