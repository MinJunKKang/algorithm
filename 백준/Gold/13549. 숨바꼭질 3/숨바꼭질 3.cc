#include <iostream>
#include <queue>

using namespace std;
#define INF 1e9

int N, K;

vector<int> dist(100001, INF);

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[N] = 0;
    pq.push({0, N});

    while (!pq.empty()) {
        auto [cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_pos == K) {
            cout << cur_dist;
            return;
        }

        if (cur_pos * 2 <= 100000 && dist[cur_pos * 2] > cur_dist) {
            dist[cur_pos * 2] = cur_dist;
            pq.push({cur_dist, cur_pos * 2});
        }

        if (cur_pos + 1 <= 100000 && dist[cur_pos + 1] > cur_dist + 1) {
            dist[cur_pos + 1] = cur_dist+1;
            pq.push({cur_dist + 1, cur_pos + 1});
        }

        if (cur_pos - 1 >= 0 && dist[cur_pos - 1] > cur_dist + 1) {
            dist[cur_pos - 1] = cur_dist;
            pq.push({cur_dist + 1, cur_pos - 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    dijkstra();

    return 0;
}