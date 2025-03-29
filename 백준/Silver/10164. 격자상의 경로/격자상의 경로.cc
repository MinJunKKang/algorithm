#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> matrix;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    if (K == 0) {
        matrix.assign(N, vector<int>(M, 1));

        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        }

        cout << matrix[N-1][M-1];
        return 0;
    }
    K--;

    int k_row, k_col;
    k_row = K/M;
    k_col = K%M;

    matrix.assign(N, vector<int>(M, 0));
    for (int i = 0; i <= k_row; i++) matrix[i][0] = 1;
    for (int j = 0; j <= k_col; j++) matrix[0][j] = 1;

    for (int i = 1; i <= k_row; i++) {
        for (int j = 1; j <= k_col; j++) matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
    }

    for (int i = k_row; i < N; i++) matrix[i][k_col] = matrix[k_row][k_col];
    for (int j = k_col; j < M; j++) matrix[k_row][j] = matrix[k_row][k_col];

    for (int i = k_row + 1; i < N; i++) {
        for (int j = k_col + 1; j < M ; j++) matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
    }

    cout << matrix[N-1][M-1];

    return 0;
}