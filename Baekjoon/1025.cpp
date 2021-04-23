#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = -1;
bool flag = false;
char arr[10][10];
bool isSqureNumber(int n) {
    int root = (int)sqrt(n);
    if (root * root == n) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    string tmp = "";
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = tmp[j-1];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int x = -n; x < n ; x++) {
                for (int y = -m; y < m; y++) {
                    if (x == 0 && y == 0) continue;
                    int a = i, b = j;
                    string now = "";
                    int number=0;
                    while (a > 0 && a <= n && b > 0 && b <= m) {
                        now += arr[a][b];
                        int number=stoi(now);
                        if (isSqureNumber(stoi(now))) ans = max(ans, number);
                        a += x;
                        b += y;
                    }
                    if (isSqureNumber(stoi(now))) ans = max(ans, number);
                }
            }
        }
    }
    cout << ans << endl;
}

/*
1.우선 N이나 M이 0이면 바로 -1을 출력한다.
2.9x9 격자에서 아무리 많이 일정한 수열을 만들어도 1억개는 넘지 않는다.
규칙 찾아서 완전탐색을 하는게 빠르다.
3.순서 고려해야 하므로 전부 세면 되고, 중복 불가.
1)시작점이 (sx,sy)이고
2)행 공차가 dx이고(-n<dx<n)
3)열 등차가 dy일 때(-m<dy<m)
해당 수열을 이어붙인 수열을 출력하는 함수를 작성한다.
기저 사례 : 시작점이 격자를 벗어나면 멈추고 출력.
---------
https://qgqg264.tistory.com/83
수열이 완성된 중간중간마다 계속 검사를 해야 한다.
수열이 반드시 끝까지 가란 법이 없기 때문에, 각 수열마다 부분 문자열을 전부 계산한다.

또 stoi같은 캐스팅 함수는 시간이 오래 걸린다. 복잡해도 숫자를 쓰는게 낫다.
*/