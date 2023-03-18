#include <bits/stdc++.h>
using namespace std;
const int INF = 2087654321;

int N;
double p[10000][2];

double area() {
	double ret = 0;
	for(int i = 0; i < N; ++i) {
		int j = (i + 1) % N;
		ret += p[i][0] * p[j][1] - p[j][0] * p[i][1];
	}
    if(ret < 0) ret *= (-1);
	return ret / 2;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%lf %lf", &p[i][0], &p[i][1]);
    }
    
    printf("%.1lf", area());
    return 0;
}

/*
자료형 범위 늘릴 때 차근차근 늘려라
*/