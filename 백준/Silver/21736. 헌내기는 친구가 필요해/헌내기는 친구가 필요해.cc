#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int result = 0;
vector<vector<bool>> visited;
vector<vector<char>> campus;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    campus.resize(N, vector<char>(M));
    visited.assign(N, vector<bool>(M, false));

    queue<pair<int, int>> DY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> campus[i][j];
            if (campus[i][j] == 'I') {
                DY.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!DY.empty()) {
        auto [cur_x, cur_y] = DY.front();
        DY.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (!inArea(nx, ny)) continue;
            if (visited[nx][ny] || campus[nx][ny] == 'X') continue;

            if (campus[nx][ny] == 'P') result++;
            visited[nx][ny] = true;
            DY.push({nx, ny});
        }
    }

    if (result == 0) cout << "TT";
    else cout << result;

    return 0;
}