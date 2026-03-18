/**
 * The falther of the segment i is [(i-1)/2] and its two sons are 
 * 2i+1 and 2i+2 , for 1 based tree : 2*i & 2*i+1
 * 
 * Build : Time Complexity : O(4*n)=O(n)
 * Query : Time Complexity : O(log(n))
 * 
 * Update : Since there are a total of log2(n) levels, 
 * there will also be log2(n)segments that need to be updated when a[x] changed.
 *         Time Complexity : O(log(n))
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int mid(int l,int r){
    return (r-l)/2+l;
}

struct SegmentTree{
    int n;
    vector<int>tree;
    SegmentTree(int n){
        this->n=n;
        tree.assign(4*n,0);
    }
    void build(int node,int tl,int tr,vector<int>&a){
        if(tl==tr)tree[node]=a[tl];
        else{
            int tm=mid(tl,tr);
            build(node*2,tl,tm,a);//for 0 based:node*2+1
            build(node*2+1,tm+1,tr,a);//for 0 based:node*2+2
            tree[node]=tree[node*2]+tree[node*2+1];//if max needed use : max(tree[node*2],tree[node*2+1])
        }
    }
    int query(int node,int tl,int tr,int l,int r){
        if(r<tl || l>tr)return 0;
        if(tl>=l && tr<=r)return tree[node];
        int tm=mid(tl,tr);
        int left=query(node*2,tl,tm,l,r);
        int right=query(node*2+1,tm+1,tr,l,r);
        return left+right;//for maximum : max(left,right)
    }
    
    void update(int node,int tl,int tr,int i,int val){
        if(tl==tr){
            tree[node]=val;
            return;
        }
        int tm=mid(tl,tr);
        if(i<=tm)update(node*2,tl,tm,i,val);
        else update(node*2+1,tm+1,tr,i,val);
        tree[node]=tree[node*2]+tree[node*2+1];//for max : max(tree[node*2],tree[node*2+1])
    }
};


int main(){
    vector<int>a={1,2,3,4,5,6,7,8};
    int n=a.size();
    SegmentTree st(n);
    st.build(1,0,n-1,a);
    cout<<st.query(1,0,n-1,2,5)<<endl; //3+4+5+6=18
 
    st.update(1,0,n-1,3,10);// a[3] = 10
    cout<<st.query(1,0,n-1,2,5)<<endl;//3+10+5+6=24
    return 0;
}