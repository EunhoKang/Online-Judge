#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n,m;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //
    return 0;
}
/*
1. 3의 40승이 최대 경우의 수이므로 직접 숫자를 넣는 일단 안된다.
2. 자리가 바뀌려면 양옆 사람이 바꾸는 수밖에 없다.
바뀔 수 있는 자리의 수는 2의 20승으로 시간안에 계산이 가능한 수준이다.
*/

/*
vector<string> split(string str,char del){
    vector<string> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(s);
    }
    return res;
}
*/