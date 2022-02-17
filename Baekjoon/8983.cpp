#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=987654321;

int m,n,L;
int shooter[100000];
pair<int,int> animal[100000];

int canShoot(pair<int,int> target, int shoot){
    return abs(target.first-shoot)<=L-target.second;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n>>L;
    for(int i=0;i<m;++i){
        cin>>shooter[i];
    }
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        animal[i]={a,b};
    }
    int shotcnt=0;
    int ans=0;
    sort(shooter,shooter+m);
    sort(animal,animal+n);
    for(int i=0;i<n;++i){
        int lo=0;
        int hi=m-1;
        int mid=0;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(canShoot(animal[i],shooter[mid])){
                ++ans;
                break;
            }else{
                if(animal[i].first<=shooter[mid]){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
1. 동물에게 가장 가까운 사대를 찾아 계산. 사대 선택에 영향을 주는 값은 x뿐이다.
이분 탐색을 통해 시간을 단축하자. n*n 탐색을 정렬된 상태에서 할수 있다면 고려 가능. 
*/