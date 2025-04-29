#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> cake(M);

    for (int i = 0; i < M; i++)
        cin >> cake[i];

    for (int i = 0; i < N; i++) {
        int count;
        cin >> count;

        int left = 1, right = L;
        int opt_value = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int cake_count = 0, pos = 0;
            for (int i = 0; i < M; i++) {
                if ((cake[i] - pos) >= mid) {
                    cake_count++;
                    pos = cake[i];
                    if (cake_count == count) break;
                }
            }

            if (cake_count < count || L - pos < mid) {
                right = mid - 1;
            } else {
                opt_value = mid;
                left = mid + 1;
            }
        }
        cout << opt_value << '\n';
    }

    return 0;
}
