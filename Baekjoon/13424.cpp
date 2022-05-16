#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=87654321;

int T;
int n,m;
int grid[101][101];
int fr;
int target[101];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        for(int i=0;i<101;++i)
            for(int j=0;j<101;++j)
                grid[i][j]=INF;
        for(int i=0;i<101;++i)
            grid[i][i]=0;
            
        cin>>n>>m;
        for(int i=0;i<m;++i){
            int a,b,c;
            cin>>a>>b>>c;
            grid[a][b]=grid[b][a]=c;
        }
        cin>>fr;
        for(int i=0;i<fr;++i)cin>>target[i];

        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    if(grid[i][j]>grid[i][k]+grid[k][j])
                        grid[i][j]=grid[i][k]+grid[k][j];
        
        int res=INF;
        int answer=-1;
        for(int i=1;i<=n;++i){
            int temp=0;
            for(int j=0;j<fr;++j)
                temp+=grid[target[j]][i];
            if(res>temp){
                res=temp;
                answer=i;
            }
        }
        cout<<answer<<'\n';
    }
    return 0;
}