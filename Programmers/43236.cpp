#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());

    int lo,hi,mid;
    lo=0; hi=distance+1;
    while(lo<=hi){
        mid=(lo+hi)/2;
        int N=n;
        int last=rocks[0];
        int res=1000000000;
        for(int i=1;i<rocks.size();++i){
            int temp=rocks[i]-last;
            if(temp<mid){
                if(N>0){
                    --N;
                    continue;
                }else{
                    res=temp;
                    break;
                }
            }else{
                last=rocks[i];
                res=min(res,temp);
            }
        }
        if(res>mid) lo=mid+1;
        else if(res<mid) hi=mid-1;
        else {
            answer=max(answer,mid);
            lo=mid+1;
        }
    }
    return answer;
}

/*
1.앞에서부터 징검다리를 건넌다.
생각해 둔 답의 후보를 정하고, 다음 바위로 건널 때 지점 사이 거리가
1) 후보 답보다 크다면 -> 해당 거리를 저장해 지금까지의 값들 중 최소인지 판별
2) 작다면 -> 바위를 없애 거리를 늘린다.
더 없앨 수 없다면(갯수 초과) 해당 값을 최소값으로 하고 반복문 중지
2.이후 구한 최소값을 후보 답과 비교해 이분 탐색으로 범위를 좁힌다.
3.이 때 mid==min(distance) 여도 이보다 큰 min 값이 존재할 수 있으므로,
lo=mid+1로 설정한 후 범위가 완전히 없어질 때까지 탐색하며 더 큰 값을 찾는다.
*/