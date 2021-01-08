#include <iostream>
#include <math.h>
using namespace std;

int n,k;

int main(){
    long long cut[10]={9,90,900,9000,90000,900000,9000000,90000000,900000000,999999999};
    cin>>n>>k;
    int cnt=0;
    long long res=0;
    while(n>cut[cnt]){
        n-=cut[cnt];
        res+=(cut[cnt]*(cnt+1));
        cnt++;
    }
    res+=(n*(cnt+1));
    if(res<k) {
        cout<<-1;
        return 0;
    }
    cnt=0;
    while(k>cut[cnt]*(cnt+1)){
        k-=cut[cnt]*(cnt+1);
        cnt++;
    }
    res=pow(10,cnt)+(int)((k-1)/(cnt+1));
    cout<<to_string(res)[((k-1)%(cnt+1))];
}

/*
1.메모리 64mb면 값을 저장하라는 게 아니라 규칙 찾아서 뽑으라는 뜻이다.
2.숫자를 자릿수별로 분류한다. 10의 0승부터 9승까지만 저장하면 된다.
일의자리부터 차례대로9,90,900,9000,90000,9000000,...,1식으로 끊긴다.
3.처리할 일은 둘이다.
1)k가 출력 가능한 수인가? 2) k번째 수가 무엇인가?
4.단위가 int 안에서 처리가 가능하닞 반드시 확인해야 한다.
*/
