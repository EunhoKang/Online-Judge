#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Node{
    int id;
    int maxR;
    int maxC;
    int w;
    vector<Node * > children;
    Node(int _id, int _maxR, int _maxC,int _w,vector<Node * > _children)
    :id(_id),maxR(_maxR),maxC(_maxC),w(_w),children(_children){};
};

int Solve(Node * r){
    int cand=0;
    int maxChild=0;
    for(int i=0;i<r->children.size();++i){
        Node * temp=r->children[i];
        cand=max(cand,Solve(temp));
        cand=max(cand,maxChild+temp->maxC);
        maxChild=max(maxChild,temp->maxC);
    }
    r->maxR=cand;
    r->maxC=maxChild+r->w;
    return cand;
}

int main() {
    Node * root;
    int n;
    cin>>n;
    vector<Node *> Nodes;
    for(int i=0;i<n;++i){
        vector<Node *> tp;
        Node * temp=new Node(i+1,0,0,0,tp);
        Nodes.push_back(temp);
    }
    root=Nodes[0];
    for(int i=0;i<n-1;++i){
        int a,b,c;
        cin>>a>>b>>c;
        Nodes[a-1]->children.push_back(Nodes[b-1]);
        Nodes[b-1]->w=c;
    }
    cout<<Solve(root);
}