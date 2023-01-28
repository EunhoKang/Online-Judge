#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;
int d[100001],p[100001][23];
bool check[100001];
vector<vector<int>> Graph;
 
void sparse(){
    for (int i = 1; i <= 20; i++)
        for (int j = 0; j < n; j++)
            p[j][i] = p[p[j][i-1]][i-1];
}
 
int lca(int x,int y){
    if(d[y] > d[x]) swap(x, y);
    for(int i = 19; i >= 0; i--)
        if((d[x]-d[y])>=(1<<i)) x = p[x][i];
    if(x == y) return x;
    for(int i = 19; i >= 0; i--)
        if(p[x][i] != p[y][i])
        {
            x = p[x][i];
            y = p[y][i];
        }
    return p[x][0];
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test_case;
	int T;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(check,0,sizeof(check));
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        Graph.clear();
 
        cin >> n;
        Graph.resize(n+3);
 
        for (int i = 1; i < n; i++){
            int x; 
            cin >> x;
            Graph[x-1].push_back(i);
        }
        for (int i = 0; i < n; i++) 
            sort(Graph[i].begin(), Graph[i].end());
 
        queue<pair<int,int>> dq;
        dq.push({0,0});
        check[0]=true;
 
        while (!dq.empty()){
            int now = dq.front().first;
            int depth = dq.front().second;
            dq.pop();
            d[now]=depth;
 
            for (int i = 0; i < Graph[now].size(); i++){
                int next = Graph[now][i];
                if (!check[next]){
                    check[next] = true;
                    p[next][0] = now;
                    dq.push({next, depth+1});
                }
            }
        }
       
        sparse();
 
        long long res=0;
        memset(check, 0, sizeof(check));
        vector<int> vt;
        queue<int> q;
        q.push(0);
        check[0]=true;
        
        while (!q.empty()){
            int now = q.front();
            q.pop();
 
            vt.push_back(now);
            for(int i=0;i<Graph[now].size();i++){
                int next = Graph[now][i];
                if(!check[next]){
                    check[next]=true;
                    q.push(next);
                }
            }
        }
        for(int i=0;i<n-1;i++){
            int LCA = lca(vt[i],vt[i+1]);
            long long a = d[vt[i]] - d[LCA];
            long long b = d[vt[i+1]] - d[LCA];
            res += a + b; 
        }
 
        cout << '#' << test_case << ' ' << res << '\n';
    }
}
