#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

int T;
string tc;
int idx;

string split(){
    string res="";
    if(tc[idx]=='b'){//모두 검은색이면 검은색만 출력, 이후 인덱스++
        res+='b';
        idx++;
    }else if(tc[idx]=='w'){//모두 흰색이면 검은색만 출력, 이후 인덱스++
        res+='w';
        idx++;
    }else{
        res+='x';
        idx++;
        string pieces[4];
        for(int i=0;i<4;++i)pieces[i]=split();//4개 조각을 분할정복
        res+=pieces[2]+pieces[3]+pieces[0]+pieces[1];//순서 바꿔서 더한다. 인덱스는 읽는데 모두 쓰였으므로 상관 없음.
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        idx=0;
        cin>>tc;
        cout<<split()<<'\n';
    }
    return 0;
}

/*
1.상하로 뒤집을 경우 필드의 변화는 다음과 같다.
1 2       3 4
3 4  ==>  1 2
또한 해당 상황에서 각 1,2,3,4 필드는 모두 상하로 뒤집힌다.
2.이 과정은 하나의 전체 필드=>4개의 작은 필드 순으로 반복되므로 이를 이용해 분할 정복을 진행한다.
1) 필드를 나눈다. 2) 4개의 필드가 모두 문자열 표현이 된다면 필드를 뒤집는다. 3) 필드를 합친다.
3.각각의 필드가 어느 인덱스에 있는지 알수 없기 때문에, 한 함수가 돌아간 후에 그 함수의 끝나는 지점을 알아야 한다.
외부 변수로 인덱스를 처리한다.
*/