#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9

int N;
vector<vector<int>> S;
vector<int> visited;
int min_diff = INF;

void calculate() {
    int start_sum = 0, link_sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (visited[i] && visited[j])
                start_sum += (S[i][j] + S[j][i]);
            else if (!visited[i] && !visited[j])
                link_sum += (S[i][j] + S[j][i]);
        }
    }

    int diff = (start_sum > link_sum ? start_sum - link_sum : link_sum - start_sum);
    min_diff = min(diff, min_diff);
}

void dfs(int idx, int count) {
    if (count == N/2) {
        calculate();
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i+1, count+1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    S.assign(N, vector<int>(N));
    visited.assign(N, false);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    dfs(0, 0);

    cout << min_diff;

    return 0;
}