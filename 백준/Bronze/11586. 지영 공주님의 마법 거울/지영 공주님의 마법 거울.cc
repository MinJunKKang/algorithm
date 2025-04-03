#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    char a[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    }

    int K;
    cin >> K;
    if (K==1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    } else if (K==2) {
        for (int i = 0; i < N; i++) {
            for (int j = N-1; j >= 0; j--) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    } else {
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}