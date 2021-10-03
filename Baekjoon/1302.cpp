#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

map<string, int> books;
int n;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){//맵을 이용해 책 등장 회수 기록
        string book;
        cin>>book;
        books[book]++;
    }
    map<string, int>::iterator it;
    int maxCount=0;
    string answer;
    for (it = books.begin(); it != books.end(); it++){//맵 순회 
        if(it->second>maxCount){//가장 많이 등장한 책 찾기
            answer=it->first;
            maxCount=it->second;
        }else if(it->second==maxCount){//등장 회수가 같다면 사전순으로 앞에 것을 찾음
            if((it->first)<answer){
                answer=it->first;
                maxCount=it->second;
            }
        }
    }
    cout<<answer;
    return 0;
}