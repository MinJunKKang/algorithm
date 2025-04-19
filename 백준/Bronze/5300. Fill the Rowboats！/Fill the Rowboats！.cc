#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        cout << i << " ";
        cnt++;

        if (cnt % 6 == 0) cout << "Go! ";
        else if (cnt == N) cout << "Go!";
    }

    return 0;
}