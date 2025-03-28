#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int M, N, H;
vector<vector<vector<int>>> tomato;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int dz[2] = {-1, 1};

bool inArea(int x, int y, int z) {
    return x >= 0 && x < N && y >= 0 && y < M && z >= 0 && z < H;
}

void bfs() {
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[j][k][i] == 1) {
                    q.push(make_tuple(j, k, i));
                }
            }
        }
    }

    while (!q.empty()) {
        auto [cur_x, cur_y, cur_z] = q.front();
        q.pop();

        int new_dist = tomato[cur_x][cur_y][cur_z]+1;
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            int nz = cur_z;

            if (!inArea(nx, ny, nz)) continue;

            if (tomato[nx][ny][nz] == 0) {
                tomato[nx][ny][nz] = new_dist;
                q.push(make_tuple(nx, ny, nz));
            }
        }
        for (int i = 0; i < 2; i++) {
            int nx = cur_x;
            int ny = cur_y;
            int nz = cur_z + dz[i];

            if (!inArea(nx, ny, nz)) continue;

            if (tomato[nx][ny][nz] == 0) {
                tomato[nx][ny][nz] = new_dist;
                q.push(make_tuple(nx, ny, nz));
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    tomato.resize(N, vector(M, vector<int>(H)));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) cin >> tomato[j][k][i];
        }
    }

    bfs();
    int min_day = -1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++)
                if (tomato[j][k][i] == 0) {
                    cout << -1;
                    return 0;
                } else {
                    min_day = max(min_day, tomato[j][k][i]);
                }
        }
    }

    cout << min_day - 1;

    return 0;
}