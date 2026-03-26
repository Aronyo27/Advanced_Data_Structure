#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *child[26];
    bool endMark=false;
    Node(){
        for(int i=0;i<26;i++)child[i]=nullptr;
    }
};

int countDistictSubstring(string &s){
    Node*root=new Node();
    int cnt=0;

    for(int i=0;i<s.size();i++){
        Node *node=root;
        for(int j=i;j<s.size();j++){
            int idx=s[j]-'a';
            if(node->child[idx]==nullptr){
                node->child[idx]=new Node();
                cnt++;
            }
            node=node->child[idx];          
        }
    }
    return cnt+1;
}

int main(){
    string s;cin>>s;
    cout<<countDistictSubstring(s)<<endl;
    return 0;
}     