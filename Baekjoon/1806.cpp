#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=2100000000;

int n, s;
int S[100000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    for( int i = 0; i < n; ++i ) cin >> S[i];
    if( s == 0 ) {
        cout << 0;
        return 0;
    }
    int startPoint = 0, endPoint = 0;
    int sum = S[0];
    int minLength = INF;
    while( startPoint < n && endPoint < n ) {
        if( sum >= s ) minLength = min ( minLength, endPoint - startPoint + 1 );
        if( startPoint < n - 1 && endPoint < n - 1 ) {
            if( sum - S[startPoint] >= s ) {
                sum -= S[startPoint];
                startPoint++;
            }
            else if( sum - S[startPoint] + S[endPoint] >= s ) {
                endPoint++;
                sum += S[endPoint] - S[startPoint];
                startPoint++;
            }
            else {
                endPoint++;
                sum += S[endPoint];
            }
        }
        else if( endPoint >= n - 1 ) {
            if( sum - S[startPoint] >= s ) { 
                sum -= S[startPoint];
                startPoint++;
            }
            else break;
        }
    }
    cout << ( minLength <= n ? minLength : 0 );
    return 0;
}

/*
1. 단순히 모든 연속 부분 수열에 대해 직접 작업을 시행하면 O(N^2)의 시간복잡도를 갖는다.
이때 N이 최대 십만이므로 연산 횟수가 1억회를 넘어가게 되어 시간복잡도에 걸린다.
2. 연속된 배열을 구하는 문제이므로 구간의 값을 저장하고 양 끝을 1씩만 증가시켜 비교한다.
예를 들어 맨 처음 원소를 빼도 조건을 만족하는 구간이라면 빼고,
맨 처음 원소를 빼고 포함되지 않은 원소 중 가장 앞의 원소를 포함하면 조건을 만족할 경우 구간 전체를 한 칸 슬라이드하고,
둘다 아닐 경우 포함되지 않은 원소 중 가장 앞의 원소를 포함한다.
더 이상 원소를 포함할 수 없을 경우 포함된 원소 중 맨 처음의 원소를 계속 빼면서 조건을 만족하는지 확인한다.
3. 0인 경우에 대해 예외처리가 필요하다. s==0이면 바로 0을 출력하고,
최소 길이가 전체 길이보다 길거나 같아도 0을 출력한다.
*/