#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    return 0;
}
/*
1. 최단거리의 손님을 찾는다. 손님이 남아있지 않다면 성공, 손님이 남아있으나 찾을 수 없다면 실패.
2. 최단거리의 손님을 목적지까지 최단 거리로 운송한다. 목적지로 갈수 없거나 연료보다 이동거리가 크면 실패.
3. 2번 과정에서 이동한 거리의 두배만큼 연료가 찬다. 1번으로 돌아간다.
4. 
*/