#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int N, M, X;
vector<pair<int, int>> adj[1001];       // 일반 그래프 (i → X 가는 경로)
vector<pair<int, int>> rev_adj[1001];   // 역방향 그래프 (X → i로 가는 경로)

// 다익스트라 알고리즘
vector<int> dijkstra(int start, vector<pair<int, int>> graph[]) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        for (auto &[next, next_dist] : graph[cur]) {
            int new_dist = cur_dist + next_dist;
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

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int A, B, T;
        cin >> A >> B >> T;
        adj[A].push_back({B, T});   // 정방향 그래프 (i → X)
        rev_adj[B].push_back({A, T}); // 역방향 그래프 (X → i)
    }

    // 다익스트라 2번만 실행
    vector<int> dist_to_X = dijkstra(X, rev_adj); // X에서 모든 정점으로 가는 거리
    vector<int> dist_from_X = dijkstra(X, adj);   // 모든 정점에서 X로 가는 거리

    int max_time = 0;
    for (int i = 1; i <= N; i++) {
        max_time = max(max_time, dist_from_X[i] + dist_to_X[i]);
    }

    cout << max_time << "\n";

    return 0;
}
