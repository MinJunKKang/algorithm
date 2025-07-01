#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;

    string str; cin >> str;
    stack<char> s;

    int stackSize = 0;
    for (char c: str) {
        if (c == '(') {
            stackSize++;
            if (!s.empty()) {
                s.pop();
            }
        } else {
            stackSize--;
            if (s.empty()) {
                result += stackSize;
                s.push(')');
            } else {
                result++;
            }
        }
    }
    cout << result;

    return 0;
}