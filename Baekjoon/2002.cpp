#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    map<string,int> m;
    vector<int> Q;
    int cnt=0;
    for(int i=0;i<N;++i){
        string temp;
        cin>>temp;
        if(m.find(temp)==m.end()){
            m.insert(make_pair(temp,cnt));
            cnt++;
        }
    }
    for(int i=0;i<N;++i){
        string temp;
        cin>>temp;
        Q.push_back(m[temp]);
    }
    int res=0;
    reverse(Q.begin(),Q.end());

    for(int i=1;i<N;++i){
        if(Q[i-1]<Q[i]){
            res++;
            int target=i;
            while(target>0 && Q[target-1]<Q[target]){
                int tp=Q[target];
                Q[target]=Q[target-1];
                Q[target-1]=tp;
                target--;
            }
        }

    }
    cout<<res;
}

/*
1.해싱을 통해 정수형 변수로 바꿔 저장한다.
처음 들어온 순서를 0,1,2,3...같이 정렬된 수열로 두고,
나중에 들어온 순서를 정렬하다보면 몇개의 차량이 추월했는지 알수 있다.
2. 추월한 횟수는 역전이 발생한 횟수. 삽입 정렬을 사용한다.
O(n^2)지만 차량 수가 1000대 이하이므로 시간 내에 풀수 있다.
3.입력 순서와 실제 차량의 위치관계는 반대이다. 배열을 뒤집어줘야 한다.
*/