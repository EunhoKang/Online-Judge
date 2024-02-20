#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N, X, Y;
int arr[4001];
int parent[4001];
int depth[4001];

int lca(int a, int b)
{
    if (depth[a] > depth[b])
		swap(b, a);
    while (depth[a] < depth[b])
        b = parent[b];
    while(a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string temp;
    cin >> N >> temp >> X >> Y;
    stack<int> s;
    int v = 0;
    for (int i = 1; i <= temp.length(); i++)
    {
        if (temp[i - 1] == '0')
        {
            arr[i] = v++;
            s.push(arr[i]);
            depth[arr[i]] = s.size();
        } 
        else 
        {
            arr[i] = s.top();
            s.pop();
            parent[arr[i]] = s.empty() ? 0 : s.top();
        }
    }
    int cut = lca(arr[X], arr[Y]);
    for (int i = 1; i <= temp.length(); i++)
    {
        if (arr[i] == cut)
        {
            cout << i << " ";
        }
    }
}