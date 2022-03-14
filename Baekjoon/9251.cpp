#include <bits/stdc++.h>
using namespace std;

string A,B;
int cache[1001][1001];

int main() {
    getline(cin,A);
    getline(cin,B);
    for (int i = 1; i<=A.size(); i++)
        for (int j = 1; j<=B.size(); j++)
            cache[i][j] = 
            max( cache[i][j - 1], max( cache[i - 1][j],cache[i - 1][j - 1] + (A[i-1] == B[j-1]) ));
    cout<<cache[A.size()][B.size()];
}

/*
https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence
*/