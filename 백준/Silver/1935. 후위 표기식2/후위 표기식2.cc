#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int N;

    cin >> N;

    string expr;

    cin >> expr;

    vector<double> value(N);

    for (int i = 0; i < N; ++i) cin >> value[i];

    stack<double> st;

    for (char ch : expr) {

        if ('A' <= ch && ch <= 'Z') {

            st.push(value[ch - 'A']);

        } else {

            double b = st.top(); st.pop();

            double a = st.top(); st.pop();

            double res = 0;

            switch (ch) {

                case '+': res = a + b; break;

                case '-': res = a - b; break;

                case '*': res = a * b; break;

                case '/': res = a / b; break;

            }

            st.push(res);

        }

    }

    cout << fixed << setprecision(2) << st.top() << '\n';

    return 0;

}