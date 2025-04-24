#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    int result = -1;
    vector<int> result_set;
    for (int i = M; i <= N; i++) {
        if (sqrt(i) == int(sqrt(i))) {
            result += i;
            result_set.push_back(i);
        }
    }

    if (result_set.empty()) cout << result;
    else {
        cout << result + 1 << '\n' << result_set[0];
    }

    return 0;
}