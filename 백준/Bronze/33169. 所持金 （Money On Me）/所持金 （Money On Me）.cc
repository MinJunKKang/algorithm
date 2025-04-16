#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A;
    cin >> B;

    cout << B * 10000 + A * 1000;
    
    return 0;
}