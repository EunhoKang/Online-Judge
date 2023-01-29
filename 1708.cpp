#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

struct vector2 {
	long long x, y;
	explicit vector2(long long x_ = 0, long long y_ = 0) : x(x_), y(y_){}
};

long long ccw(vector2 a, vector2 b, vector2 c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

typedef vector<vector2> polygon;
int n;
vector2 points[100001];

bool comp_y(vector2 a, vector2 b) {
	if (a.y != b.y)	return a.y < b.y;
	else return a.x < b.x;
}

bool comp_c(vector2 a, vector2 b) {
	long long cc = ccw(points[0], a, b);
	if (cc != 0) return cc > 0;
	else if (a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}

polygon GrahamsScan() {
	polygon hull;
	stack<vector2> s;
	
	sort(points, points + n, comp_y);
	sort(points + 1, points + n, comp_c);

	s.push(points[0]);
	s.push(points[1]);
	points[n++] = vector2(points[0].x , points[0].y);
	vector2 first, second;

	for (int i = 2; i < n; i++) {
		cout << i << " " << points[i].x << " " << points[i].y << '\n';
		while (s.size() >= 2) {
			second = s.top();
			s.pop();
			first = s.top();
			cout << "ccw : " << first.x << " " << first.y <<" " << second.x <<" " << second.y << '\n';
			if (ccw(first, second, points[i]) > 0) {
				s.push(second);
				break;
			}
		}
		s.push(points[i]);
	}
	s.pop();
	
	while (!s.empty()) {
		hull.push_back(s.top());
		s.pop();
	}
	return hull;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
		int a, b;
        cin >> a >> b;
        points[i] = vector2(a, b);
    }
	cout << GrahamsScan().size();
    return 0;
}

/*
1. 범위가 -40000~40000이라 long long을 써야 한다.
2. ccw 연산은 실수 연산을 최소화하기 위해 외적을 활용한다.
3. 마지막에 껍질을 닫아야 하기 때문에, 마지막 점 추가까지 신경쓴다.
*/