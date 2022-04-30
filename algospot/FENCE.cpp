#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1187654321;

int T;
int n;
int fences[20001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>fences[i];
        fences[n+1]=0;
        stack<int> st;
        st.push(0);
        int sum=0; 
        for(int i=1;i<=n+1;++i){
            int cnt=0;
            while(fences[st.top()]>fences[i]){
                int h=st.top();
                st.pop();
                sum=max(sum,(i-st.top()-1)*fences[h]);
            }
            st.push(i);
        }
        cout<<sum<<'\n';
    }
    return 0;
}

/*
1.분할 정복, 스위핑 알고리즘, 이진탐색 모두 가능한 문제.스위핑 알고리즘을 선택했다. 
2.어차피 튀어나온 위쪽 꼭지는 의미가 없음을 이용.
1)가장 최근에 받는 막대의 길이가 받아야 할 막대의 길이보다 길다면, 그러한 모든 막대를 pop.
스택에서 막대가 하나 빠질 때마다 넓이를 구하고 비교해나간다.
2)이렇게 하면 모든 막대가 오름차순으로 정리되며 스택에 남는 막대들은 전부 오니쪽 끝 막대의 후보군.
따라서 스택에는 막대의 길이가 아닌 인덱스를 저장하고, 인덱스의 차이를 이용해 가로 길이를 계산.
세로 길이는 pop한 막대의 길이이다.
3)맨 마지막에 길이 0 인 막대를 집어넣으면 모든 막대를 날리면서 넓이를 계산하므로 반드시 넓이를 구할 수 있다.
3.안풀려서 풀이 보면서 풀었습니다 https://lovelykon.tistory.com/2
*/