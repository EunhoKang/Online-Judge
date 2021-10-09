#include <bits/stdc++.h>
using namespace std;
#define ll long long
int INF=987654321;

using namespace std;

int n;
int A[500001];
int temp[500001];
long long inversion=0;

void Merge(int start, int last){
    int mid = (start + last) / 2;
    int LIndex=start;
    int RIndex=mid+1;
    int tempIndex=start;
    while(tempIndex<=last){
        if(LIndex>mid){
            temp[tempIndex]=A[RIndex];
            RIndex++;
        }else if(RIndex>last){
            temp[tempIndex]=A[LIndex];
            LIndex++;
        }else{
            if(A[LIndex]<=A[RIndex]){
                temp[tempIndex]=A[LIndex];
                LIndex++;
            }else{
                temp[tempIndex]=A[RIndex];
                RIndex++;
                inversion+=(long long)(mid+1-LIndex);
            }
        }
        tempIndex++;
    }
    for(int i=start;i<=last;++i){
        A[i]=temp[i];
    }
}

void Split(int start, int last)
{
	if (start < last) {
		int mid = (start + last) / 2;
		Split(start, mid);
		Split(mid + 1, last);
		Merge(start, last);
	}
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>A[i];
    Split(0,n-1);
    cout<<inversion;
    return 0;
}

/*
https://blog.daum.net/rhaoslikesan/282
버블 소트의 스왑은 역전 수와 정확히 일치한다.
합병 정렬을 통해 역전의 수를 세면 된다.

중복되는 수가 허용되므로 고려해서 부등호를 써야 한다.
*/