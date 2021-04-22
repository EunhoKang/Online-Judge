#include <bits/stdc++.h>
using namespace std;

void PrintArray(vector<vector<int>> arr){
    for(int i=0;i<arr.size();++i){
        for(int j=0;j<arr[i].size();++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}

vector<vector<int>> SpinArray(vector<vector<int>> arr){
    int temp;
    int n=arr.size();
    int mid=n/2;
    for(int i=0;i<mid;++i){
        temp=arr[i][i];
        arr[i][i]=arr[mid][i];
        arr[mid][i]=arr[n-1-i][i];
        arr[n-1-i][i]=arr[n-1-i][mid];
        arr[n-1-i][mid]=arr[n-1-i][n-1-i];
        arr[n-1-i][n-1-i]=arr[mid][n-1-i];
        arr[mid][n-1-i]=arr[i][n-1-i];
        arr[i][n-1-i]=arr[i][mid];
        arr[i][mid]=temp;
    }
    return arr;
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0; i<N; ++i){
        int n, angle;
        cin>>n>>angle;
        vector<vector<int>> array;
        for(int a=0;a<n;++a){
            vector<int> temp;
            for(int b=0; b<n;++b){
                int tp;
                cin>>tp;
                temp.push_back(tp);
            }
            array.push_back(temp);
        }
        int cnt=(angle+360)%360/45;
        for(int k=0;k<cnt;++k){
            array=SpinArray(array);
        }
        PrintArray(array);
    }
    return 0;
}

/*
1.d의 각도는 360을 더하고 나머지를 내서 얼마나 돌릴지를 계산한다.
왼쪽으로 1번 돌리는게 오른쪽으로 7번 돌리는 것과 같고 시간 제한도 넉넉해 하나만 구현해도 된다.
2.n=500이므로 동적 배열 활용
*/