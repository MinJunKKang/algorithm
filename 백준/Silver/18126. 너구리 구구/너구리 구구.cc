#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
#define INF 1e13

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> adj[N+1];
    for (int i = 0; i < N-1; i++) {
        int A, B, C; cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }

    vector<ll> dist(N+1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        auto [c_dist, pos] = pq.top(); pq.pop();

        if (dist[pos] < c_dist) continue;

        for (auto &[np, nd]: adj[pos]) {
            ll new_dist = c_dist + nd;
            if (new_dist < dist[np]) {
                dist[np] = new_dist;
                pq.push({new_dist, np});
            }
        }
    }

    ll result = -1;
    for (int i = 1; i <= N; i++) {
        result = max(dist[i], result);
    }

    cout << result;

    return 0;
}