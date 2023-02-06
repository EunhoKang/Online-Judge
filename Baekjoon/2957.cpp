#include <bits/stdc++.h>
using namespace std;

map<int, int> tree;
int n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    long long C = 0;
    int root;
    cin >> root;
    tree[root] = 0;
    cout << 0 << '\n';
    for (int i = 1; i < n; ++i)
    {
        int item, cmp1 = 0, cmp2 = 0;
        cin >> item;
        auto it = tree.lower_bound(item);
        if (it != tree.end())
            cmp1 = it->second;
        if (it != tree.begin())
        {
            --it;
            cmp2 = it->second;
        }
        tree[item] = max(cmp1, cmp2) + 1;
        C += tree[item];
        cout << C << '\n';
    }
}

/*
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ehddml1229&logNo=221013489684
*/