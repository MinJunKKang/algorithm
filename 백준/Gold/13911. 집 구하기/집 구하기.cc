#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define INF 1e9

int V, E;
vector<pair<int, int>> adj[10001];
int M, x;
int S, y;
vector<int> dist_mcd, dist_starbucks;
set<int> restricted;

vector<int> dijkstra(vector<int>& starts) {
    vector<int> dist(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int start : starts) {
        dist[start] = 0;
        pq.push(make_pair(dist[start], start));
    }

    while (!pq.empty()) {
        auto [cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur_pos]) continue;

        for (auto [next_pos, next_dist] : adj[cur_pos]) {
            int nd = cur_dist + next_dist;
            if (dist[next_pos] > nd) {
                dist[next_pos] = nd;
                pq.push(make_pair(nd, next_pos));
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cin >> M >> x;
    vector<int> mac(M);
    for (int i = 0; i < M; i++) {
        cin >> mac[i];
        restricted.insert(mac[i]);
    }

    cin >> S >> y;
    vector<int> star(S);
    for (int i = 0; i < S; i++) {
        cin >> star[i];
        restricted.insert(star[i]);
    }

    dist_mcd = dijkstra(mac);
    dist_starbucks = dijkstra(star);

    int min_sum = INF;

    for (int i = 1; i <= V; i++) {
        if (restricted.count(i)) continue;
        if (dist_mcd[i] <= x && dist_starbucks[i] <= y) {
            min_sum = min(min_sum, dist_mcd[i] + dist_starbucks[i]);
        }
    }

    cout << (min_sum == INF ? -1 : min_sum) << "\n";

    return 0;
}