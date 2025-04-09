#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<bool>> visited_saekyak;
int result = 0;
int result_saekyak = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x>=0 && x<N && y>=0 && y < N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    grid.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));
    visited_saekyak.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++)
            cin >> grid[i][ii];
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> q_saekyak;
    bool saekyak_blue = false;
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++) {
            if (!visited[i][ii]) {
                q.push({i, ii});
                visited[i][ii] = true;
                result++;
            }

            if (!visited_saekyak[i][ii]) {
                q_saekyak.push({i, ii});
                visited_saekyak[i][ii] = true;
                result_saekyak++;
                if (grid[i][ii] == 'B') saekyak_blue = true;
                else saekyak_blue = false;
            }

            while (!q.empty()) {
                auto [cur_x, cur_y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];

                    if (!inArea(nx, ny)) continue;

                    if (!visited[nx][ny] && grid[cur_x][cur_y] == grid[nx][ny]) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }

            while (!q_saekyak.empty()) {
                auto [cur_x, cur_y] = q_saekyak.front();
                q_saekyak.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];

                    if (!inArea(nx, ny)) continue;

                    if (!visited_saekyak[nx][ny]) {
                        if (saekyak_blue && grid[nx][ny] == 'B') {
                            q_saekyak.push({nx, ny});
                            visited_saekyak[nx][ny] = true;
                        } else if (!saekyak_blue && grid[nx][ny] != 'B') {
                            q_saekyak.push({nx, ny});
                            visited_saekyak[nx][ny] = true;
                        }
                    }
                }
            }

        }
    }

    cout << result << " " << result_saekyak;

    return 0;
}