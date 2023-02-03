#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int endpoint;
    Node * child[10];
};

Node * Tree;

void FreeAll(Node * root){
    if(root==NULL) return;
    for(int i=0;i<10;++i){
        FreeAll(root->child[i]);
    }
    free(root);
}

void Input(){
    int n;
    cin>>n;
    vector<string> S;
    for(int i=0;i<n;++i){
        string tp;
        cin>>tp;
        S.push_back(tp);
    }
    Node * temp=new Node();
    temp->endpoint=0;
    Tree=temp;

    sort(S.begin(),S.end());
    for(int i=0;i<n;++i){
        string tp=S[i];
        int pnt=0;
        Node * pointer=Tree;
        while(pnt<tp.size()){
            if(pointer->endpoint==1){
                cout<<"NO";
                return;
            }else{
                if(pointer->child[(S[i][pnt]-'0')]==NULL){
                    Node * n=new Node();
                    n->endpoint=0;
                    pointer->child[(S[i][pnt]-'0')]=n;
                }
                pointer=pointer->child[(S[i][pnt]-'0')];
            }
            pnt++;
        }
        pointer->endpoint=1;
    }
    cout<<"YES";
    FreeAll(Tree);
}

int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        Input();
        cout<<'\n';
    }
}

/*
1. 트라이를 쓰진 않았지만 비슷한 트리 구조를 활용했다.
각 노드마다 10개의 자식 노드를 두어 각 번호와 대응시킨다.
만약 마지막 노드가 아닌데 탐색이 종료되면 일관성이 없다는 뜻.
*/