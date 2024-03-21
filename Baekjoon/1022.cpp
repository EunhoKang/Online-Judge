#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int swirl(int r, int c)
{
    int k = max(abs(r), abs(c));
    if (k == 0) return 1;
    int mx = (2 * k - 1) * (2 * k - 1);
    int len = 2 * k;
    int half = k;
    if (c == k && r < c)
    {
        return mx + half - r;
    }
    else if (r == -k && c < k)
    {
        return mx + len + half - c;
    }
    else if (c == -k && -k < r)
    {
        return mx + len * 2 + half + r;
    }
    else
    {
        return mx + len * 3 + half + c;
    }
}

string blank(int n)
{
    string result = "";
    for (int i = 0; i < n; ++i)
    {
        result += " ";
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    vector<vector<int>> result;
    int maxlen = 0;
    for (int i = r1; i <= r2; ++i)
    {
        vector<int> temp;
        for (int j = c1; j <= c2; ++j)
        {
            int cell = swirl(i, j);
            maxlen = max(maxlen, (int)to_string(cell).length());
            temp.push_back(cell);
        }
        result.push_back(temp);
    }
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << blank(maxlen - to_string(result[i][j]).length()) << result[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

/*
* �־��� ������ �۱� ������ �ð��̳� �޸𸮴� ������� �ʾƵ� �ȴ�.
* Ư�� ��ǥ������ ���� f(x, y)�� �� �� f(x, x) = (2x + 1) ^ 2�̴�. �̸� M(x)�� ����.
* f(x, y)���� k = max(|x|, |y|)�� ��, M(k - 1) < f(x, y) <= M(k)�̴�.
* �� ���� �Լ��� ����� ���� �����ϰ�, �̸� ���� ������ ������ ����Ѵ�.
*/