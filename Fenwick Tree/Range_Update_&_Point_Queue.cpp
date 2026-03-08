#include<bits/stdc++.h>
using namespace std;

struct Fenwick{
    int n;
    vector<int>bit;
    Fenwick(int n){
        this->n=n;
        bit.assign(n+1,0);
    }
    void update(int i,int val){
        while(i<=n){
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    void rangeUpdate(int l,int r,int val){
        update(l,val);
        update(r+1,-val);
    }
    int pointQuery(int i){
        return query(i);
    }  
};

int main(){
    
    int n,q; cin>>n>>q;
    Fenwick fw(n);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fw.rangeUpdate(i,i,a[i]);
    }
    while(q--){
        int type;cin>>type;
        if(type==1){
            int l,r,val; cin>>l>>r>>val;
            fw.rangeUpdate(l,r,val);
        }else if(type==2){
            int idx; cin>>idx;
            cout<<fw.pointQuery(idx)<<endl;
        }
    }
    return 0;
}