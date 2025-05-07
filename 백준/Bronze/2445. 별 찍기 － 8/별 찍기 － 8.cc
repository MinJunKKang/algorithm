#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        for (int j = N-1; j > i; j--) {
            cout << " ";
        }
        for (int j = N-1; j > i; j--) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for (int i = N-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        for (int j = N-1; j >= i; j--) {
            cout << " ";
        }
        for (int j = N-1; j >= i; j--) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
