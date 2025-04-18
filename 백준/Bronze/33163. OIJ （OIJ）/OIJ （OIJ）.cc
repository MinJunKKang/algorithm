#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<char> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 0; i < N; i++) {
        if (a[i] == 'J') cout << 'O';
        else if (a[i] == 'O') cout << 'I';
        else cout << 'J';
    }

    return 0;
}