#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    if ( A + B + C <= 21 ) cout << 1;
    else cout << 0;

    return 0;
}