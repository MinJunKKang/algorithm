#include <iostream>
#include <queue>
#include <set>
#include <vector>
typedef long long ll;

using namespace std;
#define INF 1e15

int N, M, K;
vector<pair<int, int>> adj[100001];
set<int> restricted;
vector<ll> dist_iv;

vector<ll> dijkstra(vector<int> &starts) {
    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    for (int start: starts) {
        pq.push(make_pair(0, start));
        dist[start] = 0;
    }

    while (!pq.empty()) {
        auto [cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur_pos]) continue;

        for (auto [next_pos, next_dist]: adj[cur_pos]) {
            ll nd = cur_dist + (ll) next_dist;
            if (nd < dist[next_pos]) {
                dist[next_pos] = nd;
                pq.push(make_pair(nd, next_pos));
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int U, V, C;
        cin >> U >> V >> C;
        adj[V].push_back({U, C});
    }

    vector<int> interview_pos(K);
    for (int i = 0; i < K; i++) {
        cin >> interview_pos[i];
        restricted.insert(interview_pos[i]);
    }

    dist_iv = dijkstra(interview_pos);

    ll max_dist = -1;
    int max_pos = -1;
    for (int i = 1; i <= N; i++) {
        if (restricted.count(i) || dist_iv[i] == INF) continue;
        if (dist_iv[i] > max_dist) {
            max_dist = dist_iv[i];
            max_pos = i;
        }
    }

    cout << max_pos << "\n" << max_dist;

    return 0;
}