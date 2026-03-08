/**
 * update → O(log n * log m)
 * query  → O(log n * log m)
 */

#include<bits/stdc++.h>
using namespace  std;

struct BIT2D{
    int n,m;
    int bit[1005][1005];
    void init(int _n,int _m){
        n=_n;
        m=_m;
        memset(bit,0,sizeof(bit));
    }
    void update(int x,int y,int val){
        for(int i=x;i<=n;i+=(i&-i)){
            for(int j=y;j<=m;j+=(j&-j)){
                bit[i][j]+=val;
            }
        }
    }
    int query(int x,int y){
        int s=0;
        for(int i=x;i>0;i-=(i&-i)){
            for(int j=y;j>0;j-=(j&-j)){
                s+=bit[i][j];
            }
        }
        return s;
    }
    int rectangle_sum(int x1,int y1,int x2,int y2){
        return query(x2,y2)
            -query(x1-1,y2)
            -query(x2,y1-1)
            +query(x1-1,y1-1);
    }
};

int main(){
    int n,m,q;cin>>n>>m>>q;
    BIT2D fw;
    fw.init(n,m);
    while(q--){
        int type;cin>>type;
        if(type==1){
            int x,y,val;cin>>x>>y>>val;
            fw.update(x,y,val);
        }else if(type==2){
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<fw.rectangle_sum(x1,y1,x2,y2)<<endl;
        }
    }
}
