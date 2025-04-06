#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9

int R, C;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vector<char>> grid;
vector<vector<bool>> is_over;
int s_x = INF;
int l_x = 0;
int s_y = INF;
int l_y = 0;

bool inArea(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void check() {
    for (int I = 0; I < R; I++) {
        for (int II = 0; II < C; II++) {
            if (grid[I][II] == 'X') {
                int cnt = 0;
                for (int III = 0; III < 4; III++) {
                    int nx = I + dx[III];
                    int ny = II + dy[III];

                    if (!inArea(nx, ny)) {
                        cnt++;
                        continue;
                    }

                    if (grid[nx][ny] == '.') cnt++;
                }

                if (cnt >= 3) {
                    is_over[I][II] = true;
                } else {
                    s_x = min(s_x, I);
                    l_x = max(l_x, I);
                    s_y = min(s_y, II);
                    l_y = max(l_y, II);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    grid.resize(R, vector<char>(C));
    is_over.resize(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cin >> grid[i][j];
    }

    check();

    for (int I = s_x; I <= l_x; I++) {
        for (int II = s_y; II <= l_y; II++) {
            if (is_over[I][II] == true) {
                cout << '.';
                continue;
            }

            cout << grid[I][II];
        }
        cout << '\n';
    }

    return 0;
}