#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int V, M;
vector<pair<int, int>> adj[1001];
int J, S;

vector<int> dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(V+1, INF);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [cdist, cpos] = pq.top(); pq.pop();

        if (cdist > dist[cpos]) continue;

        for (auto [npos, ndist]: adj[cpos]) {
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

    cin >> V >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cin >> J >> S;
    vector<int> arriveTime_J = dijkstra(J);
    vector<int> arriveTime_S = dijkstra(S);

    int bestSum = INF;
    int bestJ = INF;
    int ans = -1;
    for (int i = V; i >= 1; i--) {
        if (i == J || i == S) continue;
        if (arriveTime_S[i] == INF || arriveTime_J[i] == INF) continue;

        int timeSum = arriveTime_S[i] + arriveTime_J[i];
        bestSum = min(timeSum, bestSum);
    }

    for (int i = V; i >= 1; i--) {
        if (i == J || i == S) continue;
        if (arriveTime_S[i] == INF || arriveTime_J[i] == INF) continue;

        int timeSum = arriveTime_S[i] + arriveTime_J[i];
        if (timeSum != bestSum) continue;
        if (arriveTime_J[i] > arriveTime_S[i]) continue;

        if (bestJ >= arriveTime_J[i]) {
            bestJ = arriveTime_J[i];
            ans = i;
        }
    }

    cout << ans;

    return 0;
}