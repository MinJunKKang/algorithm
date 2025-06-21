#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> N >> K;

    vector<int> dist(100001, INF);
    vector<int> number(100001, 0);

    queue<int> q;
    q.push(N);
    dist[N] = 0;
    number[N] = 1;
    int count = 0;

    while (!q.empty()) {
        int a = q.front(); q.pop();

        if (a == K) {
            count++;
        }

        if ((a-1) >= 0) {
            if (dist[a-1] == INF) {
                dist[a-1] = dist[a] + 1;
                q.push(a-1);
            }
            if (dist[a-1] == dist[a] + 1) {
                number[a-1] += number[a];
            }
        }

        if ((a+1) <= 100000) {
            if (dist[a+1] == INF) {
                dist[a+1] = dist[a] + 1;
                q.push(a+1);
            }
            if (dist[a+1] == dist[a] + 1) {
                number[a+1] += number[a];
            }
        }

        if ((a*2) <= 100000) {
            if (dist[a*2] == INF) {
                dist[a*2] = dist[a] + 1;
                q.push(a*2);
            }
            if (dist[a*2] == dist[a] + 1) {
                number[a*2] += number[a];
            }
        }
    }

    cout << dist[K] << '\n' << number[K];

    return 0;
}