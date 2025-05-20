#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9


using namespace std;

int N;
int A, B, C;
int M;

struct Edge{
    int to, w;
};
vector<Edge> adj[100001];

vector<int> dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N+1, INF);

    dist[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto [cDist, cPos] = pq.top(); pq.pop();

        if (cDist > dist[cPos]) continue;

        for (auto &e: adj[cPos]) {
            int new_dist = e.w + cDist;
            if (dist[e.to] > new_dist) {
                dist[e.to] = new_dist;
                pq.emplace(new_dist, e.to);
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> A >> B >> C;

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> aDist = dijkstra(A);
    vector<int> bDist = dijkstra(B);
    vector<int> cDist = dijkstra(C);

    int ans = 0, ans_val = 0;
    for (int i = 1; i <= N; i++) {
        vector<int> tmp(3); tmp[0] = aDist[i]; tmp[1] = bDist[i]; tmp[2] = cDist[i];
        sort(tmp.begin(), tmp.end());
        if (ans_val < tmp[0]) {
            ans_val = tmp[0];
            ans = i;
        }
    }

    cout << ans;

    return 0;
}
