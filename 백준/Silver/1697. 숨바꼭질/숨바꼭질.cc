#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vector<int> dist(100001, -1);

    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int a = q.front(); q.pop();

        if (a == K) break;

        if ((a-1) >= 0 && dist[a-1] == -1) {
            dist[a-1] = dist[a] + 1;
            q.push(a-1);
        }

        if ((a+1) <= 100000 && dist[a+1] == -1) {
            dist[a+1] = dist[a] + 1;
            q.push(a+1);
        }

        if ((a*2) <= 100000 && dist[a*2] == -1) {
            dist[a*2] = dist[a] + 1;
            q.push(a*2);
        }
    }

    cout << dist[K];

    return 0;
}
