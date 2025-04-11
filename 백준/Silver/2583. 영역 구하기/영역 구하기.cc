#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<int> q_size;
int result = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

void bfs() {
    queue<pair<int, int>> pos;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1 || visited[i][j]) continue;
            int k = 1;
            result++;
            pos.push({i, j});
            visited[i][j] = true;

            while (!pos.empty()) {
                auto [cur_x, cur_y] = pos.front();
                pos.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];

                    if (!inArea(nx, ny)) continue;

                    if (!visited[nx][ny] && grid[nx][ny] == 0) {
                        pos.push({nx, ny});
                        visited[nx][ny] = true;
                        k++;
                    }
                }
            }

            q_size.push_back(k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    grid.resize(M, vector<int>(N, 0));
    visited.resize(M, vector<bool>(N, false));

    for (int I = 0; I < K; I++) {
        int l_x, l_y, r_x, r_y;
        cin >> l_x >> l_y >> r_x >> r_y;

        for (int R = (M-1-l_y); R > (M-1-r_y); R--) {
            for (int C = l_x; C < r_x; C++)
                grid[R][C] = 1;
        }
    }

    bfs();

    sort(q_size.begin(), q_size.end());
    cout << result << "\n";
    for (int i : q_size) {
        cout << i << " ";
    }

    return 0;
}