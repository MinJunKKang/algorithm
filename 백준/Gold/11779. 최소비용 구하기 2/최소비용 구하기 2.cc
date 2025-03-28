#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>

using namespace std;

#define INF 1e9

//도시의 개수, 버스의 개수
int n, m, city_start, city_end;

//비용
vector<int> dist(1001, INF);
vector<pair<int, int>> adj[1001]; // 도착노드, 거리
vector<int> prev_node(1001, 0);

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push(make_pair(0, src)); // {거리, 도착지}

    while (!pq.empty()) {
        auto [cur_dist, cur_src] = pq.top();
        pq.pop();

        if (dist[cur_src] < cur_dist) continue;

        for (auto &[next, next_dist]: adj[cur_src]) {
            int new_dist = cur_dist + next_dist;
            if (dist[next] > new_dist) {
                prev_node[next] = cur_src;
                dist[next] = new_dist;
                pq.push(make_pair(new_dist, next));
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(v, w));
    }

    cin >> city_start >> city_end;

    dijkstra(city_start);

    vector<int> path;
    for (int i = city_end; i != 0; i = prev_node[i]) {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());

    cout << dist[city_end] << '\n' << path.size() << '\n';
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }

    return 0;
}