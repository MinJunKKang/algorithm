#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, M, A, B, C;
struct Edge {
    int to, w;
};
vector<Edge> adj[11];

bool dijkstra(int limit) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N+1, INF);

    dist[A] = 0;
    pq.push({0, A});

    while (!pq.empty()) {
        auto [curDist, curPos] = pq.top(); pq.pop();

        if (curDist > dist[curPos]) continue;

        for (auto &e: adj[curPos]) {
            if (e.w > limit) continue;
            int new_dist = e.w + curDist;
            if (new_dist < dist[e.to] && new_dist <= C) {
                dist[e.to] = new_dist;
                pq.push({new_dist, e.to});
            }
        }
    }

    return dist[B] <= C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> A >> B >> C;

    vector<int> cost;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        cost.push_back(w);
    }

    sort(cost.begin(), cost.end());
    cost.erase(unique(cost.begin(), cost.end()), cost.end());

    int lft = 0, rgt = (cost.size() - 1), ans = -1;

    while (lft <= rgt) {
        int mid = (lft + rgt) / 2;
        if (dijkstra(cost[mid])) {
            ans = cost[mid];
            rgt = mid - 1;
        } else {
            lft = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
