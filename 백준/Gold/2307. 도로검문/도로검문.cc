#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int N, M;
struct Edge {
    int to, w, id;
};
vector<Edge> adj[1001];
vector<pair<int, int>> parent;

int dijkstra(int ignore) {
    vector<int> dist(N+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        auto [c_dist, c_pos] = pq.top(); pq.pop();

        if (dist[c_pos] < c_dist) continue;

        for (auto &n: adj[c_pos]) {
            if (n.id == ignore) continue;

            int nd = c_dist + n.w;
            if (nd < dist[n.to]) {
                dist[n.to] = nd;
                pq.push({nd, n.to});
                if (ignore == -1) {
                    parent[n.to] = {c_pos, n.id};
                }
            }
        }
    }


    return dist[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, t; cin >> a >> b >> t;
        adj[a].push_back({b, t, i});
        adj[b].push_back({a, t, i});
    }

    parent.assign(N+1, {-1, -1});

    int origin = dijkstra(-1);

    vector<int> path;
    // 경로의 id로 저장해놓자 -> 최단경로
    for (int v = N; v != 1; v = parent[v].first) {
        path.push_back(parent[v].second);
    }

    int ans = 0;
    for (int ban: path) {
        int d = dijkstra(ban);
        if (d == INF) {
            cout << -1;
            return 0;
        }
        ans = max(ans, d - origin);
    }

    cout << ans;

    return 0;
}