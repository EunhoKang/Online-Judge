#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> m;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size();i++){
        for(int j=0;j<phone_book[i].size();++j){
            string temp=phone_book[i].substr(0,j+1);
            if(m.find(temp)!=m.end()){
                answer=false;
                return answer;
            }
        }
        m.insert(make_pair(phone_book[i],1));
    }
    return answer;
}

int main(){
    cout<<solution({"119", "97674223", "1195524421"});
}