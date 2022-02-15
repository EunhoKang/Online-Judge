#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int n;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    queue<int> deck;
    for(int i=1;i<=n;++i){
        deck.push(i);
    }
    while(deck.size()>1){
        deck.pop();
        int temp=deck.front();
        deck.push(temp);
        deck.pop();
    }
    cout<<deck.front();
    return 0;
}