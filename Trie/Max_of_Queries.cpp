/**
 * You are given an array arr of N non-negative integers.
You are also given Q queries, where each query is of the form [xi, ai].
For each query, find the maximum value of:
xi XOR arr[j]
such that:
arr[j] ≤ ai
If no such element exists:
Return -1 for that query.

Output:
Return an array of answers for all queries.
 */

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*child[2];
    Node(){
        child[0]=child[1]=nullptr;
    }
};

struct TrieNode{
    Node*root=new Node;
    void insert(int n){
        Node*cur=root;
        for(int i=31;i>=0;i--){
            int in=(n>>i)&1;
            if(!cur->child[in])cur->child[in]=new Node();
            cur=cur->child[in];
        }
    }
    int findMaxXor(int n){
        Node *cur=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            int need=1-bit;
            if(cur->child[need]){
                ans=ans|(1<<i);
                cur=cur->child[need];
            }else cur=cur->child[bit];
        }
        return ans;
    }
};
vector<int> maxXorQueries(vector<int>& arr, vector<vector<int>>& queries){
    sort(arr.begin(), arr.end());

    vector<tuple<int, int, int>> offlineQueries;  //Store queries as (ai, xi, index)

    for (int i = 0; i < queries.size(); i++) {
        int xi = queries[i][0];
        int ai = queries[i][1];
        offlineQueries.push_back({ai,xi,i});
    }
    sort(offlineQueries.begin(),offlineQueries.end());

    TrieNode trie;
    vector<int>ans(queries.size());
    int j=0;
    int n=arr.size();
    for (auto &q : offlineQueries) {
        int ai = get<0>(q);
        int xi = get<1>(q);
        int idx = get<2>(q);
        while (j < n && arr[j] <= ai) {
            trie.insert(arr[j]);
            j++;
        }
        if (j == 0) {
            ans[idx] = -1;
        } else {
            ans[idx] = trie.findMaxXor(xi);
        }
    }
    return ans;
}

int main() {
    vector<int>arr={0,1,2,3,4};
    vector<vector<int>>queries={{3,1},{1,3},{5,6}};
    vector<int>result=maxXorQueries(arr,queries);
    for (int x:result) {
        cout<<x<<" ";
    }
    return 0;
}