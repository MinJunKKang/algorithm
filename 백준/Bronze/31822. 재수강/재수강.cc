#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string code;
    cin >> code;

    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string k;
        cin >> k;

        bool same = true;
        for (int i = 0; i < 5; i++) {
            if (code[i] != k[i]) same = false;
        }

        if (same) cnt++;
    }

    cout << cnt;

    return 0;
}