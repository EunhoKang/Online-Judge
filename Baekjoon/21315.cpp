#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lastorder[1000], midorder[1000];
int k1=0,k2=0,n;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>lastorder[i];
    for(int i=0;i<n;++i){
        if(lastorder[i]==n){
            while(i>1){
                i/=2;
                k2++;
            }
            break;
        }
    }
    int tp;
    for(int i=0;i<k2;++i){
        int mid=pow(2,i);
        for(int j=0;j<mid;++j){
            tp=lastorder[j+mid];
            lastorder[j+mid]=lastorder[j];
            lastorder[j]=tp;
        }
    }
    int cnt=0;
    for(int i=pow(2,k2);i<n;++i){
        midorder[cnt]=lastorder[i];
        cnt++;
    }
    for(int i=0;i<pow(2,k2);++i){
        midorder[cnt]=lastorder[i];
        cnt++;
    }
    for(int i=0;i<n;++i){
        if(midorder[i]==1){
            while(i>1){
                i/=2;
                k1++;
            }
            break;
        }
    }
    cout<<k1<<" "<<k2;
    return 0;
}

/*
1.가장 밑에 있는 카드는 반드시 맨 위로 올라가게 된다.
따라서 첫 섞기때 반드시 맨 위에 있는 카드는 N이다.
가장 먼저 주어진 카드 순서 중 가장 큰 수를 찾기 전까지 있는 카드의 수가
2번째 섞기에서 처음 섞게 된 카드의 수가 되고, 이를 이용해 두번째 K를 알 수 있다.

2.초기에는 정렬되어 있으므로 한번 섞은 상태에서는 가장 큰 수가 반드시 앞으로,
가장 작은 수가 반드시 맨 뒤로 가야 한다.
이를 이용해 가장 작은 수가 나오기 전까지 몇 개의 수가 있는지를 세면
첫번째 K 역시 알 수 있다.

3.차례로 계산한다.
1)두번째 K를 구한다.
2)중간 카드 더미 상태를 만든다.
3) 첫번째 K를 구한다.
시간복잡도는 2번 과정에 지배되는데, 2^K가 N에 근접할 때 O(NlogN)이므로
충분히 시간 안에 구할 수 있다.
*/