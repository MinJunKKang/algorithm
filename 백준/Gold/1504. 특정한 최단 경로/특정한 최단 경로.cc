#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int N, E, v1, v2;
vector<pair<int, int>> adj[801];

vector<int> dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N + 1, INF);
    
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        for (auto [next, cost] : adj[cur]) {
            int new_dist = cur_dist + cost;
            if (new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push({new_dist, next});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> E;
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    // 1번 정점, v1, v2에서 다익스트라 실행
    vector<int> dist1 = dijkstra(1);
    vector<int> distV1 = dijkstra(v1);
    vector<int> distV2 = dijkstra(v2);

    // 두 가지 경로 계산
    int c1 = (dist1[v1] == INF || distV1[v2] == INF || distV2[N] == INF) ? INF : dist1[v1] + distV1[v2] + distV2[N];
    int c2 = (dist1[v2] == INF || distV2[v1] == INF || distV1[N] == INF) ? INF : dist1[v2] + distV2[v1] + distV1[N];

    // 최단 거리 선택
    int result = min(c1, c2);
    cout << (result == INF ? -1 : result) << "\n";

    return 0;
}
