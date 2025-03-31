#include <iostream>
#include <vector>
#include <tuple>

typedef long long ll;

using namespace std;
#define INF 1e9

int N, M;
vector<tuple<int, int, int>> adj;

vector<ll> bellman_ford() {
    vector<ll> dist(N+1, INF);
    dist[1] = 0;

    for (int i = 1; i < N; i++) {
        for (auto [u, v, w]: adj) {
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto [u, v, w]: adj) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            return {};
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        adj.push_back({A, B, C});
    }

    vector<ll> result = bellman_ford();

    if (result.empty()) {
        cout << -1;
        return 0;
    }

    for (int i = 2; i <= N; i++) {
        cout << (result[i] == INF ? -1 : result[i]);
        cout << '\n';
    }

    return 0;
}