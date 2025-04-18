#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    while (N--) {
        string S;
        cin >> S;
        if (S[0] == 'C') cnt++;
    }
    cout << cnt;

    return 0;
}