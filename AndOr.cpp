#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    int n;
    bool isTopLevelAND;

    SegmentTree(const vector<int>& A) {
        n = A.size();
        tree.resize(4 * n);
        isTopLevelAND = (n % 2 == 0);  // Determines if the top-level operation is AND
        build(A, 0, 0, n - 1, isTopLevelAND);
    }

    void build(const vector<int>& A, int node, int start, int end, bool isAND) {
        if (start == end) {
            tree[node] = A[start];
        } else {
            int mid = (start + end) / 2;
            build(A, 2 * node + 1, start, mid, !isAND);
            build(A, 2 * node + 2, mid + 1, end, !isAND);

            if (isAND)
                tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
            else
                tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }

    void update(int index, int value, int node, int start, int end, bool isAND) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid)
                update(index, value, 2 * node + 1, start, mid, !isAND);
            else
                update(index, value, 2 * node + 2, mid + 1, end, !isAND);

            if (isAND)
                tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
            else
                tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }

    int getBeauty() {
        return tree[0];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    SegmentTree segTree(A);

    int q;
    cin >> q;
    while (q--) {
        int p, x;
        cin >> p >> x;
        p--;

        if (A[p] != x) {
            A[p] = x;
            segTree.update(p, x, 0, 0, n - 1, segTree.isTopLevelAND);
        }

        cout << segTree.getBeauty() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
