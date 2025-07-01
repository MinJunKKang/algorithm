#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    int result = 0;
    while (N--) {
        string str; cin >> str;
        stack<char> s;

        for (char c: str) {
            if (s.empty() || s.top() != c) s.push(c);
            else if (s.top() == c) s.pop();
        }
        if (s.empty()) result++;
    }
    cout << result;

    return 0;
}