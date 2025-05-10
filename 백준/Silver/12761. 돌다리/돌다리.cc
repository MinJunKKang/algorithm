#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int A, B, N , M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> N >> M;

    queue<int> q;
    vector<int> dist(100001, -1);
    dist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int pos = q.front(); q.pop();
        if (pos == M) break;

        if ((pos - 1) >= 0 && dist[pos-1] == -1) {
            dist[pos-1] = dist[pos] + 1;
            q.push(pos-1);
        }
        if ((pos - A) >= 0 && dist[pos-A] == -1) {
            dist[pos-A] = dist[pos] + 1;
            q.push(pos-A);
        }
        if ((pos - B) >= 0 && dist[pos-B] == -1) {
            dist[pos-B] = dist[pos] + 1;
            q.push(pos-B);
        }
        if ((pos+1) <= 100000 && dist[pos+1] == -1) {
            dist[pos+1] = dist[pos] + 1;
            q.push(pos+1);
        }
        if ((pos+A) <= 100000 && dist[pos+A] == -1) {
            dist[pos+A] = dist[pos] + 1;
            q.push(pos+A);
        }
        if ((pos+B) <= 100000 && dist[pos+B] == -1) {
            dist[pos+B] = dist[pos] + 1;
            q.push(pos+B);
        }
        if ((pos*A) <= 100000 && dist[pos*A] == -1) {
            dist[pos*A] = dist[pos] + 1;
            q.push(pos*A);
        }
        if ((pos*B) <= 100000 && dist[pos*B] == -1) {
            dist[pos*B] = dist[pos] + 1;
            q.push(pos*B);
        }
    }

    cout << dist[M];

    return 0;
}
