#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int m = (int)N.size(), matched = 0;
    vector<int> pi(m, 0);
    for(int i = 1; i< m ; i++){
        while(matched > 0 && N[i] != N[matched])
            matched = pi[matched - 1];
        if(N[i] == N[matched])
            pi[i] = ++matched;
    }
    return pi;
}

vector<int> kmpSearch(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	int matched = 0;
	for (int i = 0; i < n; ++i)
	{
		while (matched > 0 && H[i] != N[matched]) matched = pi[matched - 1];
		if (H[i] == N[matched])
		{
			++matched;
			if (matched == m)
			{
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string H, N;
    getline(cin, H);
    getline(cin, N);
    vector<int> kmp = kmpSearch(H, N);
    cout << kmp.size() << '\n';
    for (int i = 0; i < kmp.size(); ++i)
        cout << kmp[i] + 1 << '\n';
    return 0;
}

/*
kmp 활용
*/