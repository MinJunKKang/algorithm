#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
typedef long long ll;

using namespace std;

int V, E;
vector<pair<int, int>> adj[100001];
vector<int> road(10);
int start;

vector<int> dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(10001, INF);
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

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < 10; i++) {
        cin >> road[i];
    }

    int l = 0, r = 1;
    vector<ll> arriveTime(10, INF);
    arriveTime[0] = 0;
    while (true) {
        vector<int> dist_cur = dijkstra(road[l]);

        while (r < 10 && dist_cur[road[r]] == INF) r++;
        if (r >= 10) break;
        arriveTime[r] = arriveTime[l] + dist_cur[road[r]];
        l = r++;
    }

    cin >> start;

    vector<int> dist = dijkstra(start);

    int ans = -1;
    for (int i = 0; i < 10; i++) {
        int v = road[i];
        if (arriveTime[i] != INF && dist[road[i]] <= arriveTime[i]) {
            if (ans == -1 || v < ans) ans = v;
        }
    }

    cout << ans;

    return 0;
}