#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int minimal[3][5]={{0,0,1,0,0},{0,1,0,1,0},{1,1,1,1,1}};
int n;

bool Star(int y, int x, int depth){
    if(depth==3)return minimal[y][x];
    if(depth-1-y<=x && x<=depth-1+y){
        if(y>=depth/2 && y-1<x && x<2*depth-1-y){
            return false;
        }else{
            if(y<depth/2){
                return Star(y,x-depth/2,depth/2);
            }else{
                if(x<depth)return Star(y-depth/2,x,depth/2);
                else return Star(y-depth/2,x-depth,depth/2);
            }
        }
    }else return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<2*n-1;++j){
            if(Star(i,j,n))cout<<'*';
            else cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

/*
분할은 용이한 형태로 문제에 맞춰 자르는 게 좋다.
*/