#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int result;
    if (N == 1) {
        result = 1;
    } else if (N == 2) {
        result = min(4, (M+1)/2);
    } else {
        if (M < 7) {
            result = min(4, M);
        } else {
            result = M - 2;
        }
    }

    cout << result;

    return 0;
}
