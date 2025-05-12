#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int n, m;
vector<pair<int, int>> adj[100001];
int s, t;

vector<int> dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n+1, INF);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [cdist, cpos] = pq.top(); pq.pop();

        if (cdist > dist[cpos]) continue;

        for (auto &[npos, ndist]: adj[cpos]) {
            int new_dist = cdist + ndist;
            if (new_dist < dist[npos]) {
                dist[npos] = new_dist;
                pq.push({new_dist, npos});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> s >> t;

    vector<int> dist = dijkstra(s);

    cout << dist[t];

    return 0;
}