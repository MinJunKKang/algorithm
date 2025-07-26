#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<char> move(N);

    for (int i = 0; i < N; i++) cin >> move[i];

    vector<vector<char>> mat(101, vector<char>(101, '#'));

    int def_x = 50, def_y = 50;
    int max_x = 50, max_y = 50;
    int min_x = 50, min_y = 50;
    mat[50][50] = '.';
    int def_direct = 0;

    for (char i: move) {
        if (i == 'R') {
            def_direct = (def_direct - 1) < 0 ? 3: def_direct-1;
        } else if (i == 'L') {
            def_direct = (def_direct + 1) % 4;
        } else {
            def_x += dx[def_direct]; def_y += dy[def_direct];
            max_x = max(def_x, max_x); max_y = max(def_y, max_y);
            min_x = min(def_x, min_x); min_y = min(def_y, min_y);
            mat[def_x][def_y] = '.';
        }
    }

    for (int i = min_x; i <= max_x; i++) {
        for (int j = min_y; j <= max_y; j++) {
            cout << mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}