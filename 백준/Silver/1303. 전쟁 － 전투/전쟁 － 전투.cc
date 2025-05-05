#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool inArea(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<char>> war(M, vector<char>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cin >> war[i][j];
    }

    vector<vector<bool>> visited(M, vector<bool>(N));

    int sum_w = 0, sum_b = 0;
    bool is_w = false;
    queue<pair<int, int>> q;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;

            int count = 1;
            if (war[i][j] == 'W') is_w = true;
            else is_w = false;

            visited[i][j] = true;
            q.push({i, j});

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (!inArea(nx, ny)) continue;
                    if (visited[nx][ny]) continue;

                    if (war[x][y] == war[nx][ny]) {
                        count++;
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }

            if (is_w) sum_w += (count*count);
            else sum_b += (count*count);
        }
    }
    cout << sum_w << " " << sum_b;

    return 0;
}
