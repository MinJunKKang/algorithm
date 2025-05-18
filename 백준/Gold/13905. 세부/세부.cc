#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e12
typedef long long ll;

using namespace std;

int N, M;
int s, e;
struct Edge {
    int to, w;
};
vector<Edge> adj[100001];
vector<int> cost;

bool ok(int limit) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<ll> dist(N+1, INF);

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [cost, pos] = pq.top(); pq.pop();

        if (cost > dist[pos]) continue;

        for (auto &e: adj[pos]) {
            if (e.w < limit) continue;
            int nd = e.w + cost;
            if (dist[e.to] > nd) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
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
    cin >> s >> e;

    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        cost.push_back(w);
    }

    sort(cost.begin(), cost.end());
    cost.erase(unique(cost.begin(), cost.end()), cost.end());

    int lft = 0, rgt = cost.size() - 1, ans = 0;
    while (lft <= rgt) {
        int mid = (lft + rgt) / 2;

        if (ok(cost[mid])) {
            lft = mid + 1;
            ans = cost[mid];
        } else {
            rgt = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
