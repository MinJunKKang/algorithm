#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M, R;
vector<int> adj[100001];
vector<int> order(100001, 0);
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    s.push(R);

    int cnt = 1;
    while (!s.empty()) {
        int cur = s.top();
        if (order[cur] == 0) {
            order[cur] = cnt; cnt++;
        }
        s.pop();

        int size = adj[cur].size();

        for (int i = 0; i < size; i++) {
            if (order[adj[cur][i]] != 0) continue;
            s.push(adj[cur][i]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}