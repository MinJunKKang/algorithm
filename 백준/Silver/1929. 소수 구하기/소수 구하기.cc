#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<bool> sosu(N+1, false);
    sosu[1] = true;

    for (int i = 2; i <= sqrt(N); i++) {
        int j = 2;
        while (i * j <= N) {
            sosu[i * j] = true;
            j++;
        }
    }

    for (int i = M; i <= N; i++) {
        if (!sosu[i]) cout << i << '\n';
    }

    return 0;
}