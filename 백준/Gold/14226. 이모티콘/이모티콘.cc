#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define INF 1e9

using namespace std;
vector<vector<int>> dist(1001, vector<int>(1001, INF));
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int S;
    cin >> S;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({1, 1, 1});
    dist[1][1] = 0;

    while (!pq.empty()) {
        auto [cur_cnt, cur_pos, cur_copy] = pq.top();
        pq.pop();
        if (cur_pos == S) {
            cout << dist[S][cur_copy]; return 0;
        }

        if (cur_copy == 0) continue;

        if (cur_pos != cur_copy) {
            pq.push({cur_cnt+1, cur_pos, cur_pos});
        }

        if (cur_pos - 1 > 0) {
            if (dist[cur_pos - 1][cur_copy] > cur_cnt + 1) {
                dist[cur_pos - 1][cur_copy] = cur_cnt + 1;
                pq.push({cur_cnt + 1, cur_pos - 1, cur_copy});
            }
        }

        if (cur_pos + cur_copy <= 1000) {
            if (dist[cur_pos + cur_copy][cur_copy] > cur_cnt + 1) {
                dist[cur_pos + cur_copy][cur_copy] = cur_cnt + 1;
                pq.push({cur_cnt+1, cur_pos + cur_copy, cur_copy});
            }
        }
    }
}