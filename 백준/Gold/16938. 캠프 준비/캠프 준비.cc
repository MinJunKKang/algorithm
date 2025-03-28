#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9

int N, L, R, X;
vector<int> adj;
vector<bool> visited;

int cnt_valid = 0;

void dfs(int idx, int cnt, int sum, int current_min, int current_max) {
    if (cnt >= 2) {
        if (sum >= L && sum <= R && (current_max - current_min >= X)) {
            cnt_valid++;
        }
    }

    for (int i = idx; i < adj.size(); i++) {
        int next = adj[i];
        int new_sum = sum + next;

        int new_min = (cnt == 0) ? next : min(current_min, next);
        int new_max = (cnt == 0) ? next : max(current_max, next);
        dfs(i + 1, cnt + 1, new_sum, new_min, new_max);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R >> X;

    adj.resize(N); visited.assign(N, false);
    for (int i = 0; i < N; i++) {
        cin >> adj[i];
    }

    dfs(0, 0, 0, INF, 0);

    cout << cnt_valid;

    return 0;
}