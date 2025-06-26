#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;

using namespace std;

vector<ll> seg;
vector<int> A;

ll build(int node, int s, int e) {
    if (s == e) return seg[node] = A[s];

    int mid = (s + e) >> 1;
    return seg[node] = build(node<<1, s, mid)
    + build(node<<1|1, mid+1, e);
}

ll query(int node, int s, int e, int l, int r) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return seg[node];

    int mid = (s + e) >> 1;
    return query(node<<1, s, mid, l, r)
    + query(node<<1|1, mid+1, e, l, r);
}

void update(int node, int s, int e, int idx, int diff) {
    if (idx < s || e < idx) return;

    seg[node] = seg[node] + diff;

    if (s != e) {
        int mid = (s + e) >> 1;
        update(node<<1, s, mid, idx, diff);
        update(node<<1|1, mid+1, e, idx, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    A.assign(N, 0);

    int h =  (int)ceil(log2(N));
    seg.assign(1<<(h+1), 0);

    build(1, 0, N-1);

    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        if (a == 0) {
            int l, r; cin >> l >> r;
            if (l > r) {
                int tmp = l; l = r; r = tmp;
            }
            cout << query(1, 0, N-1, l-1, r-1) << '\n';
        } else {
            int idx; ll val; cin >> idx >> val;
            idx--;
            ll dif = val - A[idx];
            update(1, 0, N-1, idx, dif);
            A[idx] = val;
        }
    }

    return 0;
}