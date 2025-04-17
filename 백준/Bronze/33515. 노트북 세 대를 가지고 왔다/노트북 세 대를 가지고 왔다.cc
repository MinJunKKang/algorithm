#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t1, t2;
    cin >> t1 >> t2;
    cout << min(t1, t2);

    return 0;
}