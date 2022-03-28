#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=INT_MAX;

int T;
string st;
list<char> li;
list<char>::iterator iter;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>st;
        li.clear();
        iter=li.end();//포인터와 같다고 생각하면 된다.
        for(char c : st){
            if(c=='<'){
                if(iter!=li.begin())iter--;//반드시 맨 끝과 앞에 대해 예외처리를 해야함
            }else if(c=='>'){
                if(iter!=li.end())iter++;
            }else if(c=='-'){
                if(iter!=li.begin()){//이전 노드를 지우는 작업이므로 먼저 앞으로 간 뒤 지운다.
                    iter--;
                    iter=li.erase(iter);
                }
            }else{
                li.insert(iter,c);//단순 위치에 추가하는 작업이므로 포인터 이동 x
            }
        }
        for(char c : li){
            cout<<c;
        }
        cout<<'\n';
    }
    return 0;
}

/*
1.위치에 따른 삽입과 삭제가 O(logN)안쪽으로 일어나야 한다.
2.제대로 된 링크드리스트에 위치 포인터를 기억하고 있다면 해결 가능하다.
===
iterater는 erase를 거칠 때 같이 삭제된다. 이를 방지하기 위해 erase는 iterater를 반환하는데 그 값을 받아서 써야 한다.
*/