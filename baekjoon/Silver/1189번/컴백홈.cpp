#include <iostream>
#include <vector>

using namespace std;

int R, C, K;
vector<vector<char>> road;
vector<vector<bool>> visited;

int valid_road = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inArea(int x, int y) {
  return x >= 0 && x < R && y >= 0 && y < C;
}

void dfs(int cur_x, int cur_y, int cnt) {
  if (cnt >= K) {
    if (cur_x == 0 && cur_y == C-1) {
      valid_road++;
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = cur_x + dx[i];
    int ny = cur_y + dy[i];

    if (inArea(nx, ny) && !visited[nx][ny] && road[nx][ny] != 'T') {
      visited[nx][ny] = true;
      dfs(nx, ny, cnt + 1);
      visited[nx][ny] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C >> K;
  road.resize(R, vector<char>(C));
  visited.assign(R, vector<bool>(C, false));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> road[i][j];
    }
  }

  visited[R-1][0] = true;
  dfs(R-1, 0, 1);

  cout << valid_road;

  return 0;
}
