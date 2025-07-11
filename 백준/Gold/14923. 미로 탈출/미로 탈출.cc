#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int x, y;
    int used;
};

int N, M;
int Hx, Hy, Ex, Ey;
vector<vector<int>> miro;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inArea(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    cin >> Hx >> Hy;

    cin >> Ex >> Ey;

    miro.resize(N, vector<int>(M));
    Hx--; Hy--; Ex--; Ey--;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> miro[i][j];
    }

    vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(2, -1)));
    queue<Node> q;
    dist[Hx][Hy][0] = 0;
    q.push({Hx, Hy, 0});
    while (!q.empty()) {
        auto [x, y, used] = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!inArea(nx, ny)) continue;

            if (miro[nx][ny] == 0 && dist[nx][ny][used] == -1) {
                dist[nx][ny][used] = dist[x][y][used] + 1;
                q.push({nx, ny, used});
            }
            else if (miro[nx][ny] == 1 && used == 0 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][used] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    int a = dist[Ex][Ey][0];
    int b = dist[Ex][Ey][1];
    int ans;

    if (a == -1 && b == -1) ans = -1;
    else if (b == -1) ans = a;
    else if (a == -1) ans = b;
    else ans = min(a, b);

    cout << ans;

    return 0;
}