/**
 * A Fenwick Tree (Binary Indexed Tree) is a data structure used to
 *     efficiently calculate prefix sums and update elements in an array.
 * Calculate the sum of range [l,r]  in a function in 
 * O(log N) time
 * Update the value of element A in O(log N) time
 * Require O(n) memory
 * Easy to use and code , specially  in the case of multidimensional arrays
 */

 /**
  * Get parent : i-=(i&-1)
  *     i.2'scomplement
  *     ii.AND it with original number
  *     iii.Subtract  from original number
  * 
  * Get next :  i+=(i&-i)
  *     i.2's complement
  *     ii.AND with original number
  *     iii.Add to original number 
  */




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
            i+=(i&-i);//Get Next
        }
    }
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=(i&-i);//Get Parent
        }
        return sum;
    }
    int rangeQuery(int l,int r){
        return query(r)-query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int n,q;cin>>n>>q;

    Fenwick fw(n);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fw.update(i,a[i]);
    }
    while(q--){
        int type;cin>>type;//type=1->update & type=2->range_query
        if(type==1){
            int idx,val; cin>>idx>>val;
            fw.update(idx,val);
        }else{
            int l,r; cin>>l>>r;
            cout<<fw.rangeQuery(l,r)<<endl;
        }
    }
    return 0;
}