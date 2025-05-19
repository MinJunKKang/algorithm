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
vector<Edge> adj[100001];
vector<int> money;

int ok(int limit) {
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

    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        money.push_back(w);
    }

    sort(money.begin(), money.end());
    money.erase(unique(money.begin(), money.end()), money.end());

    int lft = 0, rgt = money.size()-1, ans = -1;

    while (lft <= rgt) {
        int mid = (lft + rgt) / 2;
        if (ok(money[mid])) {
            ans = money[mid];
            rgt = mid - 1;
        } else {
            lft = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
