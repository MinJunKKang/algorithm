#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str; cin >> str;
    vector<char> st;

    for (char c: str) {
        st.push_back(c);
        int stackSize = st.size();

        if (st[stackSize - 4] == 'P' &&
            st[stackSize - 3] == 'P' &&
            st[stackSize - 2] == 'A' &&
            st[stackSize - 1] == 'P') {
            st.pop_back();
            st.pop_back();
            st.pop_back();
        }
    }

    if (st.size() == 1 && st[0] == 'P')
        cout << "PPAP\n";
    else
        cout << "NP\n";

    return 0;
}