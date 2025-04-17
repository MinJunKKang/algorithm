#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int case_num = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << "Case " << case_num << ": Sorting... done!\n";
        case_num++;
    }

    return 0;
}