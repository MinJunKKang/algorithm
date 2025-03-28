#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;
vector<vector<int>> cheese;
vector<vector<bool>> visited;

bool inArea(int x, int y) {
    return x>=0 && x<R && y>=0 && y<C;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int tme = 0;
int result;

int bfs() {
    visited.assign(R, vector<bool>(C, false));

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    int cnt = 0;
    while (!q.empty()) {
        auto [cur_x, cur_y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (!inArea(nx, ny) || visited[nx][ny]) continue;

            visited[nx][ny] = true;

            if (cheese[nx][ny] == 0) {
                q.push({nx, ny});
            } else {
                cheese[nx][ny] = 0;
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    cheese.resize(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> cheese[i][j];
    }

    while (true) {
        int cur_cheese = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                if (cheese[i][j] == 1) cur_cheese++;
        }

        if (cur_cheese == 0) {
            cout << tme << '\n' << result;
            break;
        }

        tme++;
        result = bfs();
    }


    return 0;
}