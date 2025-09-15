#include <iostream>

using namespace std;

int w, h;

const int Max_size = 50;
bool visited[Max_size][Max_size];
int a[Max_size][Max_size];

int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

bool inArea(int x, int y) {
    return x >= 0 && y >= 0 && x < h && y < w;
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (inArea(tx, ty) && !visited[tx][ty] && a[tx][ty]) dfs(tx, ty);
    }
}

int cnt_land() {
    int land = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] && !visited[i][j]) {
                dfs(i, j);
                land++;
            }
        }
    }

    return land;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) return 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> a[i][j];
                visited[i][j] = false;
            }
        }

        int ans = cnt_land();
        cout << ans << "\n";
    }
}