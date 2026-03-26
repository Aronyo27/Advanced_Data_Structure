/**
 * Problem: Maximum XOR Between Two Arrays
 * 
You are given two arrays of integers:
An array arr1 of size n
An array arr2 of size m
Your task is to find the maximum value of A XOR B, where:
A is an element from arr1
B is an element from arr2
 */

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *child[2];
    Node(){
        child[0]=child[1]=nullptr;
    }
};
struct TrieNode{
    Node *root=new Node();

    void insert(int n){
        Node*cur=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(!cur->child[bit])cur->child[bit]=new Node();
           cur=cur->child[bit];
        }
    }
    int getMaxXor(int n){
        Node *cur=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            int want=1-bit;
            if(cur->child[want]){
                ans=ans|(1<<i);
                cur=cur->child[want];
            }else{
                cur=cur->child[bit];
            }
        }
        return ans;
    }

    
};




signed main(){
    int n,m;cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(int &i:a)cin>>i;
    for(int &i:b)cin>>i;
    int ans=0;
    TrieNode trie;

    for(int &i:a)trie.insert(i);
    for(int &i:b){
        ans=max(ans,trie.getMaxXor(i));
    }
    cout<<ans<<endl;
    return 0;
}