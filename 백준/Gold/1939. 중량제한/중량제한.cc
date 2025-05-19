#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, M;
int s, e;
struct Edge {
    int to, cost;
};
vector<Edge> adj[10001];
vector<int> w;

bool ok(int weight) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N+1, INF);

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [cDist, cPos] = pq.top(); pq.pop();

        if (cDist > dist[cPos]) continue;

        for (auto &n: adj[cPos]) {
            if (n.cost < weight) continue;
            int new_dist = cDist + 1;
            if (dist[n.to] > new_dist) {
                dist[n.to] = new_dist;
                pq.push({new_dist, n.to});
            }
        }
    }

    return dist[e] != INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, C; cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
        w.push_back(C);
    }
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());

    cin >> s >> e;
    int lft = 0, rgt = w.size() - 1, ans = 0;
    while (lft <= rgt) {
        int mid = (lft + rgt) / 2;
        if (ok(w[mid])) {
            ans = w[mid];
            lft = mid + 1;
        } else {
            rgt = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
