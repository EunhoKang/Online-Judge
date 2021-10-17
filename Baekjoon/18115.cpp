#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
deque<int> dq;
int commands[1000001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>commands[i];
    int cnt=1;
    while(n--){
        switch(commands[n]){
            case 1 :{
                dq.push_front(cnt);
                break;
            };
            case 2 :{
                int temp=dq.front();
                dq.pop_front();
                dq.push_front(cnt);
                dq.push_front(temp);
                break;
            };
            case 3 :{
                dq.push_back(cnt);
                break;
            }
            default:{
                break;
            };
        }
        cnt++;
    }
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    return 0;
}

/*
1,3번은 덱을 활용하고 2번 동작만 잘 처리하면 된다.
*/