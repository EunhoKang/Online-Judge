#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=987654321;

int T;
int n;

int GetMid(priority_queue<int> & top,priority_queue<int> & bot){
    if(top.size()>bot.size())return -top.top();
    else return bot.top();
}

void PushMid(priority_queue<int> & top,priority_queue<int> & bot,int k){
    int mid;
    if(top.empty()&&bot.empty()){
        top.push(-k);
        return;
    }
    if(top.size()>bot.size()){
        mid=-top.top();
        if(mid<k){
            top.push(-k);
            bot.push(-top.top());
            top.pop();
        }
        else bot.push(k);
    }
    else {
        mid=bot.top();
        if(mid<k)top.push(-k);
        else {
            bot.push(k);
            top.push(-bot.top());
            bot.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    for(int I=0;I<T;++I){
        priority_queue<int> top;
        priority_queue<int> bot;
        vector<int> answer;
        cin>>n;
        for(int i=0;i<n;++i){
            int a;
            cin>>a;
            PushMid(top,bot,a);
            if(i%2==0)answer.push_back(GetMid(top,bot));
        }
        cout<<answer.size();
        for(int i=0;i<answer.size();++i){
            if(i%10==0)cout<<'\n';
            cout<<answer[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}

/*
1.우선순위 큐 둘을 이용해 중앙값을 항상 구할수 있게 만든다.
*/