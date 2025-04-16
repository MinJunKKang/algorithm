#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string K;
    cin >> K;
    int h = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
        if ((K[i] - '0') % 2 != 0) h++;
        else j++;
    }

    if (j > h) cout << 0;
    else if (j < h) cout << 1;
    else cout << -1;

    return 0;
}