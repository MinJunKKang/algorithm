#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> add_muscle;
vector<bool> visited;
int available_result = 0;

void dfs(int muscle, int cnt) {
    if (cnt == N) {
        available_result++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i])
            continue;
    
        int new_muscle = muscle + add_muscle[i] - K;
        if (new_muscle < 500)
            continue;
    
        visited[i] = true;
        dfs(new_muscle, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    add_muscle.resize(N);
    visited.assign(N, false);

    for (int i = 0; i < N; i++) {
        cin >> add_muscle[i];
    }

    dfs(500, 0);
    cout << available_result << "\n";

    return 0;
}