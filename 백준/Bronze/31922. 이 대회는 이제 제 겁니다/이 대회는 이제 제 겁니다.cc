#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, P, C;
    cin >> A >> P >> C;
    if ( A + C < P ) cout << P;
    else cout << A + C;

    return 0;
}