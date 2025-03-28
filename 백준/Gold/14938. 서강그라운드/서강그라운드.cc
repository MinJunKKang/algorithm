#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1e9

int n, m, r;
int item[101];
// 도착지, 비용
vector<pair<int, int>> adj[101];

int dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur_pos]) continue;

        for (auto &[next_pos, next_dist] : adj[cur_pos]) {
            int new_dist = cur_dist + next_dist;
            if (new_dist < dist[next_pos]) {
                dist[next_pos] = new_dist;
                pq.push({new_dist, next_pos});
            }
        }
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m)
            total += item[i];
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;

        item[i] = t;
    }

    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;

        adj[a].push_back({b,l});
        adj[b].push_back({a,l});
    }
    int result = 0;

    for (int i = 1; i <= n; i++) {
        result = max(result, dijkstra(i));
    }

    cout << result;

    return 0;
}