#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;

    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> dist(N, -1);

    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int pos = q.front(); q.pop();

        int param = A[pos];

        for (int i = pos; i <= pos + param; i++) {
            if (dist[i] == -1) {
                q.push(i);
                dist[i] = dist[pos] + 1;
            }
        }
    }

    cout << dist[N-1];

    return 0;
}