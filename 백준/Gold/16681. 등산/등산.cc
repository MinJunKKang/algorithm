#include <iostream>
#include <queue>
using namespace std;
#define INF 1e15
typedef long long ll;

int N, M, D, E;
vector<pair<int, int>> adj[100001];
int pos[100001];
int result = 0;

vector<ll> dijkstra(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(make_pair(0, start));

    vector<ll> dist(N+1, INF);
    dist[start] = 0;

    while (!pq.empty()) {
        auto [cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur_pos]) continue;

        for (auto [next_pos, next_dist] : adj[cur_pos]) {
            if (pos[next_pos] > pos[cur_pos]) {
                ll nd = cur_dist + next_dist;
                if (nd < dist[next_pos]) {
                    dist[next_pos] = nd;
                    pq.push(make_pair(nd, next_pos));
                }
            }
        }
    }

    return dist;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> D >> E;

    for (int i = 1; i <= N; i++) {
        cin >> pos[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b, n;
        cin >> a >> b >> n;
        adj[a].push_back({b, n});
        adj[b].push_back({a, n});
    }

    vector<ll> dist1 = dijkstra(1);
    vector<ll> distN = dijkstra(N);

    ll ans = -INF;

    for (int i = 1; i <= N; i++) {
        if (dist1[i] == INF || distN[i] == INF) continue;
        ll value = (ll) pos[i] * E - (dist1[i] + distN[i]) * D;
        ans = max(ans, value);
    }

    if (ans == -INF) cout << "Impossible";
    else cout << ans;

    return 0;
}