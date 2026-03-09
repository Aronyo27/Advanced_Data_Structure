/**
 * Range table is a data structure ,that allows answering range queries.
 * It's advantage is answering range minimum queries in O(1) TC
 * 
 * Any positive integer can be represented the sum of decreasing power of two.
 *      Example : 13=(1101)₂=8+4+1
 * For a number x there can be at most [log2(x)] summands
 * 
 * For update it needed to rebuild the full tree , so it need O(nlog(n)) time complexity.
 */

#include<bits/stdc++.h>
using namespace std;

struct SparseTable{
    int n,k;
    vector<int>lg;
    vector<vector<int>>st;
    SparseTable(vector<int>&a){
        n=a.size();
        k=32-__builtin_clz(n);
        lg.assign(n+1,0);
        st.assign(k,vector<int>(n));
        for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
        for(int i=0;i<n;i++)st[0][i]=a[i];

        for(int j=1;j<k;j++){
            for(int i=0;i+(1<<j)<=n;i++){
                st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
            }
        }
    }
    int query(int l,int r){
        int j=lg[r-l+1];
        return min(st[j][l],st[j][r-(1<<j)+1]);
    }
};


int main() {
    vector<int> a = {4, 6, 1, 5, 7, 3};

    SparseTable sp(a);

    cout << sp.query(1, 4) << '\n'; // 1
    cout << sp.query(1, 5) << '\n'; // 1
    cout << sp.query(3, 5) << '\n'; // 3

    return 0;
}