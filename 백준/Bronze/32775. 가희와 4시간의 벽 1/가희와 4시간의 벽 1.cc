#include <iostream>

using namespace std;

int x, y;

int main() {
    cin >> x >> y;
    if(x > y) cout << "flight";
    else cout << "high speed rail";
}