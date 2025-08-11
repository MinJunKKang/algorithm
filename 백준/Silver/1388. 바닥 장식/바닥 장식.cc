#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool inArea(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<vector<char>> mat(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        for (int j = 0; j < M; j++) {
            mat[i][j] = str[j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    int result = 0;

    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
                result++;
            }
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                if (mat[x][y] == '-') {
                    int nx = x; int ny = y + 1;
                    if (!inArea(nx, ny) || mat[nx][ny] != mat[x][y]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                } else {
                    int nx = x + 1; int ny = y;
                    if (!inArea(nx, ny) || mat[nx][ny] != mat[x][y]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    cout << result;

    return 0;
}