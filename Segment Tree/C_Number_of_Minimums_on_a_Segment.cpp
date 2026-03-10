// Practice : https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C


#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> a;

int mid(int l, int r) {
    return l + (r - l) / 2;
}

struct Node {
    int mn, cnt;
};

struct segTree {
    int n;
    vector<Node> tree;
    const int INF = (int)4e18;

    segTree(int n) {
        this->n = n;
        tree.assign(4 * n, {INF, 0});
    }

    Node merge(Node left, Node right) {
        if (left.mn < right.mn) return left;
        if (right.mn < left.mn) return right;
        return {left.mn, left.cnt + right.cnt};
    }

    void build(int node, int tl, int tr) {
        if (tl == tr) {
            tree[node] = {a[tl], 1};
            return;
        }
        int tm = mid(tl, tr);
        build(node * 2, tl, tm);
        build(node * 2 + 1, tm + 1, tr);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) return {INF, 0};
        if (l <= tl && tr <= r) return tree[node];

        int tm = mid(tl, tr);
        Node left = query(node * 2, tl, tm, l, r);
        Node right = query(node * 2 + 1, tm + 1, tr, l, r);
        return merge(left, right);
    }

    void update(int node, int tl, int tr, int i, int val) {
        if (tl == tr) {
            tree[node] = {val, 1};
            return;
        }
        int tm = mid(tl, tr);
        if (i <= tm) update(node * 2, tl, tm, i, val);
        else update(node * 2 + 1, tm + 1, tr, i, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    segTree st(n);
    st.build(1, 0, n - 1);

    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            int idx, val;
            cin >> idx >> val;
            st.update(1, 0, n - 1, idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            Node ans = st.query(1, 0, n - 1, l, r - 1);
            cout << ans.mn << ' ' << ans.cnt << '\n';
        }
    }

    return 0;
}