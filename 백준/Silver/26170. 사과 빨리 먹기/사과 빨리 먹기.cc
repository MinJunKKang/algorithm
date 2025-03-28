#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9
const int road_size = 5;

vector<vector<int>> road;
vector<vector<bool>> visited;
int r, c;
int min_move = INF;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


bool inArea(int x, int y) {
    return x >= 0 && x < road_size && y >= 0 && y < road_size;
}
void dfs(int cur_x, int cur_y, int cnt, int move) {
    if (cnt == 3) {
        min_move = min(min_move, move);
    }

    for (int i = 0; i < 4; i++) {
        int nx = cur_x + dx[i];
        int ny = cur_y + dy[i];

        if (inArea(nx, ny) && !visited[nx][ny] && road[nx][ny] != -1) {
            visited[nx][ny] = true;
            if (road[nx][ny] == 1) {
                dfs(nx, ny, cnt+1, move+1);
            } else {
                dfs(nx, ny, cnt, move+1);
            }
            visited[nx][ny] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    road.resize(road_size, vector<int>(road_size));
    visited.assign(road_size, vector<bool>(road_size, false));
    for (int i = 0; i < road_size; i++) {
        for (int j = 0; j < road_size; j++) {
            cin >> road[i][j];
        }
    }

    cin >> r >> c;

    visited[r][c] = true;
    if (road[r][c] == 1) {
        dfs(r, c, 1, 0);
    } else {
        dfs(r, c, 0, 0);
    }

    if (min_move == INF) min_move = -1;
    cout << min_move;

    return 0;
}
