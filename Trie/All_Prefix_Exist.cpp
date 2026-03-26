#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*child[26];
    bool endMark;
    Node(){
        for(int i=0;i<26;i++)child[i]=nullptr;
        endMark=false;
    }
};

class Trie{
    Node*root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string &s){
        Node*cur=root;
        for(char &c:s){
            int id=c-'a';
            if(cur->child[c]==nullptr)cur->child[id]=new Node();
            cur=cur->child[id];
        }
        cur->endMark=true;
    }
    bool allPrefixExist(const string &s){
        Node*cur=root;
        for(char c:s){
            int id=c-'a';
            if(cur->child[id]==nullptr)return false;
            cur=cur->child[id];
            if(!cur->endMark)return false;
        }
        return true;
    }
};

string completeString(int n,vector<string>&a){
    Trie trie;
    for(auto &s:a)trie.insert(s);
    string ans="";
    for(auto &s:a){
        if(trie.allPrefixExist(s)){
            if(s.size()>ans.size()){
                ans=s;
            }else if(s.size()==ans.size() && s<ans){
                ans=s;
            }
        }
    }
    if(ans=="")return "none";
    return ans;
}

signed main(){
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << completeString(n, a) << '\n';

    return 0;
}