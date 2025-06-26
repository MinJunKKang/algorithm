#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;
vector<ll> seg;
vector<ll> A;

ll build(int node, int s, int e) {
    if (s == e) return seg[node] = A[s];

    int mid = (s + e) >> 1;
    return seg[node] = build(node<<1, s, mid)
    + build(node<<1|1, mid+1, e);
}

ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];

    int mid = (s + e) >> 1;
    return query(node<<1, s, mid, l, r) + query(node<<1|1, mid+1, e, l, r);
}

void update(int node, int s, int e, int idx, ll diff) {
    if (idx < s || idx > e) return;

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

    int N, M, K; cin >> N >> M >> K;

    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int h = (int)ceil(log2(N));
    seg.assign(1 << (h+1), 0);

    build(1, 0, N-1);

    for (int i = 0; i < (M + K); i++) {
        int a; cin >> a;
        if (a == 1) {
            int b; ll c;
            cin >> b >> c;
            b--;
            ll dif = c - A[b];
            update(1, 0, N-1, b, dif);
            A[b] = c;
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, N-1, l-1, r-1) << '\n';
        }
    }

    return 0;
}
