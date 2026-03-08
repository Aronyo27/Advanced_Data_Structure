/**
 * Prefix Sum:
 *          prefix(x)=x∗sum(B1,x)−sum(B2,x)
 * Range sum:
 *          sum(l,r)=prefix(r)−prefix(l−1)
 */


#include<bits/stdc++.h>
using namespace std;

struct Fenwick{ //Value Change Track
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
};

struct RangeFenwick{ //prefix correction
    int n;
    Fenwick B1,B2;
    RangeFenwick(int n):n(n),B1(n),B2(n){}
    void range_update(int l,int r,int val){
        B1.update(l,val);
        B1.update(r+1,-val);

        B2.update(l,val*(l-1));
        B2.update(r+1,-val*r);
    }
    int p_sum(int i){
        return i*B1.query(i)-B2.query(i);
    }
    int range_query(int l,int r){
        return p_sum(r)-p_sum(l-1);
    }
};


int main(){
    int n=10;
    RangeFenwick fw(n);
    fw.range_update(2,5,3);
    fw.range_update(4,8,2);
    cout<<fw.range_query(2,5)<<endl;
    cout<<fw.range_query(1,8)<<endl;
    return 0;
}