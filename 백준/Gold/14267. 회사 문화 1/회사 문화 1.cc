#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[100001];
vector<int> praise(100001, 0);
vector<int> result(100001, 0);

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        if (i != 1) adj[k].push_back(i);
    }


    for (int j = 1; j <= m; j++) {
        int i, w; cin >> i >> w;
        praise[i] += w;
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nxt: adj[cur]) {
            result[nxt] = result[cur] + praise[nxt];
            q.push(nxt);
        }
    }

    for (int i = 1; i <= n; i++) cout << result[i] << " ";

    return 0;
}