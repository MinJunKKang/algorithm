#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, D;
    cin >> A >> B;
    cin >> C >> D;

    int a = A + D;
    int b = B + C;

    cout << (a > b ? b : a);
    return 0;
}