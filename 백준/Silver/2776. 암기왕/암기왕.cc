#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> note1(N);
        for (int i = 0; i < N; i++) cin >> note1[i];
        sort(note1.begin(), note1.end());

        int M; cin >> M;
        vector<int> note2(M);
        for (int i = 0; i < M; i++) cin >> note2[i];

        for (int c : note2) {
            int lo = 0, hi = N - 1;
            bool found = false;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (c > note1[mid]) {
                    lo = mid + 1;
                } else if (c < note1[mid]) {
                    hi = mid - 1;
                } else {
                    found = true;
                    break;
                }
            }
            cout << (found ? 1 : 0) << '\n';
        }
    }

    return 0;
}