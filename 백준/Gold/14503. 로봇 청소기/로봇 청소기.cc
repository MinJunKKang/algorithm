#include <iostream>
#include <vector>

using namespace std;

int N, M, r, c, d;
vector<vector<int>> grid;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int clean_count = 0;

void clean(int x, int y) {
    grid[x][y] = 2;
    clean_count++;
}

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;

    grid.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> grid[i][j];
    }

    while (true) {
        if (grid[r][c] == 0)
            clean(r, c);

        bool found = false;

        for (int i = 0; i < 4; i++) {
            d = (d+3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];

            if (check(nx, ny) && grid[nx][ny] == 0) {
                r = nx;
                c = ny;
                found = true;
                break;
            }
        }

        if (!found) {
            int nx = r - dx[d];
            int ny = c - dy[d];

            if (!check(nx, ny) || grid[nx][ny] == 1) {
                break;
            }

            r = nx;
            c = ny;
        }
    }

    cout << clean_count;
    return 0;
}