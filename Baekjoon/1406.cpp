#include <bits/stdc++.h>
using namespace std;
#define ll long long

list<char> li;
string str;
int n;
list<char>::iterator it;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>str>>n;
    for(int i=0;i<str.length();++i){
        li.push_back(str[i]);
    }
    li.push_back(' ');
    it=--li.end();
    cin.ignore();
    while(n--){
        string temp;
        getline(cin,temp);
        if(temp[0]=='L'){if(it!=li.begin())--it;}
        else if(temp[0]=='D'){if(it!=--li.end())++it;}
        else if(temp[0]=='B'){
            if(it!=li.begin()){
                list<char>::iterator temp=it;
                li.erase(--it);
                it=temp;
            }
        }
        else{li.insert(it,temp[2]);}
    }
    for(list<char>::iterator i=li.begin(); i!=li.end();++i)cout<<*i;
    return 0;
}

/*
1.커서가 존재할 수 있는 위치가 실제 문자열 길이보다 1 크므로 
마지막에 공백 문자를 넣는다.
2.list.erase 함수는 원소 삭제 후 바로 다음 원소를 가리킨다.
해당 문제에서는 이전 문자를 가리키도록 해야 하므로 조정이 필요하다.
3.iterator에서 erase 후 초기화를 하지 않으면 뜯겨나간 노드를 그대로 가리킨다.
적절한 위치를 기억하도록 해야 한다.
*/