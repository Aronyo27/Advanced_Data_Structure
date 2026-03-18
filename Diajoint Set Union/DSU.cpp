#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            make_set(i);
        }
    }

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same_set(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size_of_set(int v) {
        return sz[find_set(v)];
    }
};

int main() {
    int n = 5;
    DSU dsu(n);

    dsu.union_sets(1, 2);
    dsu.union_sets(2, 3);
    dsu.union_sets(4, 5);

    cout << dsu.same_set(1, 3) << '\n'; // 1
    cout << dsu.same_set(1, 5) << '\n'; // 0

    cout << dsu.size_of_set(2) << '\n'; // 3
    cout << dsu.size_of_set(4) << '\n'; // 2

    return 0;
}