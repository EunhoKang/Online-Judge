#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    sort(times.begin(),times.end());
    unsigned long long lo,hi,mid;
    lo=0;
    hi=times[times.size()-1]*n+1;
    while(lo<=hi){
        mid=(lo+hi)/2;
        unsigned long long res=0;
        for(int i=0;i<times.size();++i) res+=mid/times[i];
        if(res==n){
            mid-=1;
            unsigned long long tp=0;
            for(int i=0;i<times.size();++i) tp+=mid/times[i];
            if(tp<n) {
                mid+=1;
                answer=mid;
                break;
            }
            ++mid;
        }
        if(res>=n)hi=mid-1;
        else lo=mid+1;
    }
    answer=lo;
    return answer;
}

/*
1.https://minnnne.tistory.com/32
*/