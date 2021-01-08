#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int w,h,n;
vector<pair<int,int>> markets;
pair<int,int> x;
int precalc[4];
int R;

int main(){
    cin>>w>>h;
    R=w+w+h+h;
    precalc[0]=0;precalc[1]=w+h;precalc[2]=w+w+h;precalc[3]=w;
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        if(a==2) {
            markets.push_back(make_pair(a,w-b));
        }
        else if(a==3) {
            markets.push_back(make_pair(a,h-b));
        }
        else {
            markets.push_back(make_pair(a,b));
        }
    }
    int a,b;
    cin>>a>>b;
    int xlen;
    if(a==2) {
        xlen=precalc[a-1]+w-b;
    }
    else if(a==3) {
        xlen=precalc[a-1]+h-b;
    }
    else {
        xlen=precalc[a-1]+b;
    }
    int res=0;
    for(int i=0;i<n;++i){
        int temp=abs(precalc[markets[i].first-1]+markets[i].second-xlen);
        temp=min(temp,R-temp);
        res+=temp;
    }
    cout<<res;
}
