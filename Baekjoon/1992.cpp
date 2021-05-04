#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
string quad[64];
string answer;

string Solve(int cnt,int x, int y){
    if(cnt==1) {
        string temp="";
        return temp+quad[x][y];
    }else{
        string tr[4];
        tr[0]=Solve(cnt/2,x,y);
        tr[1]=Solve(cnt/2,x,y+cnt/2);
        tr[2]=Solve(cnt/2,x+cnt/2,y);
        tr[3]=Solve(cnt/2,x+cnt/2,y+cnt/2);
        if(tr[0]==tr[1]&&tr[1]==tr[2]&&tr[2]==tr[3]&&tr[3].size()==1) return tr[0];
        else return "("+tr[0]+tr[1]+tr[2]+tr[3]+")";
    }
    return "("+Solve(cnt/2,0,0)+Solve(cnt/2,1,0)+Solve(cnt/2,0,1)+Solve(cnt/2,1,1)+')';
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>quad[i];
    cout<<Solve(n,0,0);
    return 0;
}
/*
1.계속 4분할하여 전부 쪼개고, 값들이 모두 같으면 압축한다.
최소 단위가 되면 해당 구역의 값을 그대로 반환한다.
2.압축 판별을 할 때 이전 것들이 완벽한 0 또는 1인지 확인한다.
*/