#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const int INF = 1e9;
const int NINF = -INF;

using namespace std;

struct Node {
    int mn = INF;
    int mx = NINF;
};

vector<Node> seg;
vector<int> A;

Node merge(Node a, Node b) {
    return {min(a.mn, b.mn), max(a.mx, b.mx)};
}

Node build(int node, int s, int e) {
    if (s == e) return seg[node] = {A[s], A[s]};

    int mid = (s + e) >> 1;

    Node L = build(node<<1, s, mid);
    Node R = build(node<<1|1, mid+1, e);
    return seg[node] = merge(L, R);
}

Node query(int node, int s, int e, int l, int r) {
    if (e < l || r < s) return {INF, NINF};
    if (l <= s & e <= r) return seg[node];

    int mid = (s + e) >> 1;
    Node L = query(node<<1, s, mid, l, r);
    Node R = query(node<<1|1, mid+1, e, l, r);

    return merge(L, R);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    A.resize(N);

    for (int &x: A) cin >> x;
    int h = (int)ceil(log2(N));
    seg.assign(1<<(h+1), {});

    build(1, 0, N-1);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        Node tmp = query(1, 0, N-1, a, b);
        cout << tmp.mn << " " << tmp.mx << '\n';
    }

    return 0;
}