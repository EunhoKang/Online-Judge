#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=INT_MAX;

int n;
ll building[80000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>building[i];
    }
    stack<int> st;
    ll res=0;
    for(int i=0;i<n;++i){
        while(!st.empty() && st.top()<=building[i]){//작은 건물 전부 제거
            st.pop();
        }
        res+=st.size();//남은 건물 수만큼 남김
        st.push(building[i]);
    }
    cout<<res;
    return 0;
}

/*
1.일반적으로 일방통행에 불연속 값을 쓰는 경우 스택을 고려해볼 수 있다.
1-1.관리인이 보는 옥상의 갯수가 아니라 보여지는 옥상의 수를 센다고 생각해보자.
어차피 왼쪽에서 오른쪽으로 계속 건물이 추가된다고 했을 때 이 옥상이 몇명에게 보여지느냐를 계산해도 값은 똑같다.
1-2.건물이 들어설 때마다 스택의 top을 비교해 자신보다 큰지를 확인한다. 
더 작은 건물을 모조리 pop하면 스택 안에는 해당 건물을 볼 수 있는 건물만 남으며, 이만큼 더해주는걸 반복하면 된다.
//
수도 없이 틀리고 나서야 자료형에 문제가 있음을 알았다.
이거 근데 왜 같은 높이 빌딩에 대해서는 언급이 없는지 모르겠다. 일단 같은 높이면 못본다.
*/