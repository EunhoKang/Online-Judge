#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

int T;
vector<int> grup;
vector<int> fans;

vector<int> multiply(const vector<int> &a, const vector<int> &b){
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);
    return c;
}

//a += b*(10^k)
void addTo(vector<int> &a, const vector<int> &b, int k){
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
}

//a -= b
void subFrom(vector<int> &a, const vector<int> &b){
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b){
    int an = a.size(), bn = b.size();
    if (an < bn)
        return karatsuba(b, a);
    if (an == 0 || bn == 0)
        return vector<int>();
    if (an <= 50)
        return multiply(a, b);
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));
    vector<int> b1(b.begin() + min<int>(bn, half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> res;
    addTo(res, z0, 0);
    addTo(res, z1, half);
    addTo(res, z2, half * 2);

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        string temp;
        grup.clear();
        fans.clear();
        cin>>temp;
        for(int i=0;i<temp.length();++i)grup.push_back(temp[i]=='M');
        cin>>temp;
        for(int i=0;i<temp.length();++i)fans.push_back(temp[i]=='M');
        reverse(fans.begin(),fans.end());
        vector<int> C=karatsuba(grup,fans);
        int res=0;
        for(int i=grup.size()-1;i<fans.size();++i){
            if(C[i]==0)res++;
        }
        cout<<res<<'\n';
    }
    return 0;
}

/*
1. 남자끼리는 포옹을 하지 않고 나머지의 경우 포옹을 한다. => 논리 연산과 유사
남자->1, 여자 -> 0일 때 and 연산시 true가 나오는 경우를 두 집단 길이 차이에서 빼면 답이 나온다.
2. 자릿수가 올라갈 떄마다 연산을 하는 것이 자릿수가 올라갈 때마다 짧은 수를 올리는 곱셈과 비슷함을 느낄 수 있다.
두 배열 중 한 쪽을 거꾸로 뒤집고 자릿수가 10이 아닌 무한이라고 가정한 후 그룹 인원이 k명일 때 실제 계산을 해볼 경우 
2^k+1승 자리부터 각 자리수가 0이면 남자끼리 만난 경우가 없다는 뜻이다.
3. 이후부터는 도저히 못풀겠어서 책 참고
4. https://algospot.com/forum/read/4732/ 이진법 bitset으로도 풀수 있을거 같아서 링크 걸어둠
*/