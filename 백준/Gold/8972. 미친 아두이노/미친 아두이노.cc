#include <iostream>
#include <vector>

#define INF 1e9;

using namespace std;

int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int R, C;
pair<int, int> I_pos;

bool inArea(int x, int y) {
    return (x >= 0 && x < R && y >= 0 && y < C);
}

pair<int, int> move(int x, int y) {
    int min_dist = INF;
    int min_x, min_y;

    for (int i = 0; i < 9; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!inArea(nx, ny)) continue;

        int result = abs(I_pos.first - nx) + abs(I_pos.second-ny);
        if (min_dist > result) {
            min_dist = result;
            min_x = nx, min_y = ny;
        }
    }

    return {min_x, min_y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    vector<pair<int, int>> R_pos;

    for (int i = 0; i < R; ++i) {
        string str; cin >> str;
        for (int j = 0; j < C; ++j) {
            if (str[j] == 'I') {
                I_pos.first = i; I_pos.second = j;
            } else if (str[j] == 'R') {
                R_pos.push_back({i, j});
            }
        }
    }

    string cmd; cin >> cmd;

    int repeat = cmd.size();
    int move_count = 0;
    bool game_over = false;

    for (int i = 0; i < repeat; ++i) {
        I_pos.first += dx[(cmd[i]-48)-1];
        I_pos.second += dy[(cmd[i]-48)-1];

        move_count++;

        vector<vector<int>> cnt(R, vector<int>(C, 0));
        for (auto j: R_pos) {
            pair<int, int> k = move(j.first, j.second);
            if (k.first == I_pos.first && k.second == I_pos.second) {
                game_over = true;
                break;
            } else {
                cnt[k.first][k.second]++;
            }
        }
        if (game_over) break;

        R_pos.clear();
        for (int l = 0; l < R; l++) {
            for (int m = 0; m < C; m++) {
                if (cnt[l][m] == 1) {
                    R_pos.push_back({l, m});
                }
            }
        }
    }

    if (game_over) cout << "kraj " << move_count;
    else {
        vector<vector<char>> result_mat(R, vector<char>(C, '.'));
        result_mat[I_pos.first][I_pos.second] = 'I';
        for (auto j: R_pos) {
            result_mat[j.first][j.second] = 'R';
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << result_mat[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}