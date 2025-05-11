#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int a, b;
bool inArea(int x) {
    return x > 0 && x <= N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<int> bridge(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> bridge[i];
    }

    cin >> a >> b;

    vector<int> dist(N+1, -1);

    dist[a] = 0;
    queue<int> q;
    q.push(a);

    while (!q.empty()) {
        int x = q.front(); q.pop();

        if (x == b) break;
        int step = bridge[x];

        for (int nx = x + step; nx <= N; nx += step) {
            if (dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }

        for (int nx = x - step; nx > 0; nx -= step) {
            if (dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }

    cout << dist[b];

    return 0;
}
