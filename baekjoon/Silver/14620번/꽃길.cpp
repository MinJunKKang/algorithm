#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9

int N;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int min_cost = INF;

int costFlower(int x, int y) {
    return (grid[x][y]
    + grid[x-1][y] + grid[x+1][y]
    + grid[x][y-1] + grid[x][y+1]);
}

void markFlag(int x, int y, vector<vector<bool>> &visited, bool flag) {
    visited[x][y] = flag;
    visited[x-1][y] = flag;
    visited[x+1][y] = flag;
    visited[x][y-1] = flag;
    visited[x][y+1] = flag;
}

bool canPlant(int x, int y) {
    if (visited[x][y] || visited[x-1][y] || visited[x+1][y] || visited[x][y-1] || visited[x][y+1])
        return false;
    return true;
}

void dfs(int idx, int cnt, int cost, vector<pair<int, int>> &candidates) {
    if (cnt == 3) {
        min_cost = min(min_cost, cost);
        return;
    }

    for (int i = idx; i < candidates.size(); i++) {
        int cur_x = candidates[i].first;
        int cur_y = candidates[i].second;
        if (canPlant(cur_x, cur_y)) {
            markFlag(cur_x, cur_y, visited, true);
            dfs(idx+1, cnt+1, cost+costFlower(cur_x, cur_y), candidates);
            markFlag(cur_x, cur_y, visited, false);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    grid.resize(N, vector<int>(N));
    visited.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> grid[i][j];
    }

    vector<pair<int, int>> candidates;
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < N-1; j++) candidates.push_back(make_pair(i, j));
    }

    dfs(0, 0, 0, candidates);

    cout << min_cost;

    return 0;
}