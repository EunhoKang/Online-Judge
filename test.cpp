#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int N;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    while(N--){
        stack<string> st[2];
        int tree[2][26][2];
        memset(tree,-1,sizeof(tree));
        for(int i=0;i<1;++i){
            while(true){
                string temp;
                cin>>temp;
                if(temp=="end")break;
                st[i].push(temp);
            }
            stack<pair<int,int>> tp;
            while(!st[i].empty()){
                string temp=st[i].top();
                st[i].pop(); 
                pair<int,int> t=tp.top();
                if(temp!="nil"){
                    if(!tp.empty()){
                        tree[i][t.first][t.second]=temp[0]-'A';
                    }
                    t={t.first,t.second+1};
                    tp.pop();
                    tp.push(t);
                    tp.push({temp[0]-'A',0});
                }else{
                    t={t.first,t.second+1};
                    tp.pop();
                    tp.push(t);
                }
                if(t.second>2){
                    tp.pop();
                }
            }
        }
        for(int i=0;i<26;i++){
            sort(tree[0][i],tree[0][i]+2);
            sort(tree[1][i],tree[1][i]+2);
            if(!(tree[0][i][0]==tree[1][i][0]&&tree[0][i][1]==tree[1][i][1])){
                cout<<false;
                continue;
            }
        }
        cout<<true;
    }
    return 0;
}
/*
1. 입력 순서를 뒤집으면 전위 순회로 바뀐다.
2. 전위 순회는 사실상 dfs와 방식이 같으므로 스택을 이용해 부모 노드를 기억하여 푼다.
*/

/*
vector<string> split(string str,char del){
    vector<string> res;
    string s;
    stringstream ss(str);
    while(getline(ss,s,del)){
        res.push_back(s);
    }
    return res;
}
*/