#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 1e9

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> N >> K;

    vector<int> dist(100001, INF);
    vector<int> prev(100001, INF);

    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int tmp = q.front(); q.pop();

        if ((tmp-1) >= 0 && dist[tmp-1]==INF) {
            dist[tmp-1]=dist[tmp]+1;
            q.push(tmp-1);
            prev[tmp-1]=tmp;
        }

        if ((tmp+1) <= 100000 && dist[tmp+1]==INF) {
            dist[tmp+1]=dist[tmp]+1;
            q.push(tmp+1);
            prev[tmp+1]=tmp;
        }

        if ((tmp*2) <= 100000 && dist[tmp*2]==INF) {
            dist[tmp*2]=dist[tmp]+1;
            q.push(tmp*2);
            prev[tmp*2]=tmp;
        }
    }

    cout << dist[K] << '\n';

    stack<int> r;
    r.push(K);
    int idx = K;
    while (prev[idx] != INF) {
        r.push(prev[idx]);
        idx = prev[idx];
    }

    while (!r.empty()) {
        cout << r.top() << " "; r.pop();
    }

    return 0;
}