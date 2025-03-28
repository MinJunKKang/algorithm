#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define INF 1e9

int N, T, M, L;
vector<tuple<int, int, int>> adj[10001];

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push(make_tuple(0, 0, 1));
    vector<int> dist(N+1, INF);
    dist[0] = 0;

    while (!pq.empty()) {
        auto [cur_cost, cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_pos == N) {
            cout << cur_cost << '\n';
            return;
        }

        for (auto &[next_pos, next_dist, next_cost] : adj[cur_pos]) {
            int new_cost = cur_cost + next_cost;
            int new_dist = cur_dist + next_dist;

            if (new_dist <= T && new_cost <= M) {
                pq.push(make_tuple(new_cost, new_dist, next_pos));
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cin >> T >> M;

    cin >> L;

    for (int i = 1; i <= L; i++) {
        int s, e, t, c;
        cin >> s >> e >> t >> c;

        adj[s].push_back({e, t, c});
        adj[e].push_back({s, t, c});
    }
    
    dijkstra();

    return 0;
}