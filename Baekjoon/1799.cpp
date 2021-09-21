#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
int grid[10][10];
int plusline[20];
int minusline[20];
int maxCount[2];

void BackTracking(int cnt, int odd){
    if(cnt>maxCount[odd]){
        maxCount[odd]=cnt;
    }
    int tY=-1,tX=-1;
    for(int i=odd;i<2*n-1;i+=2){
        if(plusline[i]==0){
            for(int j=0;j<i+1;++j){
                if(i-j<n && j<n){
                    if(grid[i-j][j]==1 && minusline[2*j-i+n-1]==0){
                        tY=i-j;tX=j;
                        break;
                    }
                }
            }
        }
        if(tY!=-1)break;
    }
    if(tY==-1){
        //maxCount[odd]=max(maxCount[odd],cnt);
        return;
    }
    grid[tY][tX]=0;
    plusline[tY+tX]=1;
    minusline[tX-tY+n-1]=1;
    BackTracking(cnt+1,odd);
    plusline[tY+tX]=0;
    minusline[tX-tY+n-1]=0;
    BackTracking(cnt,odd);
    grid[tY][tX]=1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(plusline,0,sizeof(plusline));
    memset(minusline,0,sizeof(minusline));
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>grid[i][j];
        }
    }
    BackTracking(0,0);
    BackTracking(0,1);
    cout<<maxCount[0]+maxCount[1];
    return 0;
}

/*
out of range는 채점시 단순 오답으로 처리될수도 있다.
항상 반복문에 이중 배열 집어넣을때는 습관적으로 이를 체크해야 한다.
*/