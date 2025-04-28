#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> k;
    int round = 1;
    while (true) {
        string tmp;
        cin >> tmp;
        if (tmp.empty()) {
            cout << round << ". 0\n";
        } else if (tmp[0] == '-') {
            break;
        } else {
            for (char c: tmp) {
                k.push(c);
            }

            int valid = 0;
            int change_count = 0;
            while (!k.empty()) {
                char tp = k.top();
                k.pop();

                if (tp == '{') valid++;
                else if (tp == '}') valid--;

                if (valid > 0) {
                    valid-=2;
                    change_count++;
                }
            }

            while (valid < 0) {
                valid += 2;
                change_count++;
            }

            cout << round << ". " << change_count << '\n';
        }
        round++;
    }

    return 0;
}