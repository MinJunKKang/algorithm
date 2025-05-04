#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int N, K;
vector<int> dist(100001, INF);

void dijkstra() {
    dist[N] = 0;

    // dist, N
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, N});

    while (!pq.empty()) {
        auto [cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_pos == K) {
            cout << cur_dist;
            return;
        }

        if (cur_pos - 1 >= 0 && dist[cur_pos-1] > cur_dist + 1) {
            dist[cur_pos-1] = cur_dist+1;
            pq.push({cur_dist+1, cur_pos-1});
        }

        if (cur_pos + 1 <= 100000 && dist[cur_pos+1] > cur_dist + 1) {
            dist[cur_pos+1] = cur_dist+1;
            pq.push({cur_dist+1, cur_pos+1});
        }

        if (cur_pos * 2 <= 100000 && dist[cur_pos*2] > cur_dist + 1) {
            dist[cur_pos*2] = cur_dist + 1;
            pq.push({cur_dist+1, cur_pos*2});
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
