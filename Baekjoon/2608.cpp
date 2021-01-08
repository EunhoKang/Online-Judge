#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

string A,B;

int TransferChar(char L){
    if(L=='I'){
        return 1;
    }
    else if(L=='V'){
        return 5;
    }
    else if(L=='X'){
        return 10;
    }
    else if(L=='L'){
        return 50;
    }
    else if(L=='C'){
        return 100;
    }
    else if(L=='D'){
        return 500;
    }
    else if(L=='M'){
        return 1000;
    }
    return 0;
}

int TransferLom2Arb(string Lom){
    int res=0;
    for(int i=0;i<Lom.size();++i){
        if(i+1==Lom.size() || TransferChar(Lom[i])>=TransferChar(Lom[i+1])){
            res+=TransferChar(Lom[i]);
        }else{
            res-=TransferChar(Lom[i]);
        }
    }
    return res;
}

string TransferArb2Lom(int Arb){
    string res="";
    while(Arb>0){
        if(Arb>=1000){
            res+="M";
            Arb-=1000;
        }
        else if(Arb>=900){
            res+="CM";
            Arb-=900;
        }
        else if(Arb>=500){
            res+="D";
            Arb-=500;
        }
        else if(Arb>=400){
            res+="CD";
            Arb-=400;
        }
        else if(Arb>=100){
            res+="C";
            Arb-=100;
        }
        else if(Arb>=90){
            res+="XC";
            Arb-=90;
        }
        else if(Arb>=50){
            res+="L";
            Arb-=50;
        }
        else if(Arb>=40){
            res+="XL";
            Arb-=40;
        }
        else if(Arb>=10){
            res+="X";
            Arb-=10;
        }
        else if(Arb>=9){
            res+="IX";
            Arb-=9;
        }
        else if(Arb>=5){
            res+="V";
            Arb-=5;
        }
        else if(Arb>=4){
            res+="IV";
            Arb-=4;
        }
        else{
            res+="I";
            Arb-=1;
        }
    }
    return res;
}

int main(){
    cin>>A;
    cin>>B;
    int res=TransferLom2Arb(A)+TransferLom2Arb(B);
    cout<<res<<'\n'<<TransferArb2Lom(res);
}


/*
1.로마 숫자를 아라비아 숫자로 바꿀 때, 문자열을 차례대로 읽고
앞의 문자의 매칭되는 숫자가 현재 문자보다 크면 총 값에서 빼고, 아닐 경우 전부 더한다.
2.아라비아 숫자를 로마 숫자로 바꿀 때, 큰수를 계속 빼가며 문자열을 차근차근 만든다.
이때 900,90,9,400,40,4를 아예 만들어야 하는 목록에 포함시킨다.
*/
