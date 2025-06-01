#include <iostream>

using namespace std;

pair<int, int> child[26];
int N;

void preorder(int node) {
    if (node == -1) return;
    cout << char(node + 'A');
    preorder(child[node].first);
    preorder(child[node].second);
}

void inorder(int node) {
    if (node == -1) return;
    inorder(child[node].first);
    cout << char(node + 'A');
    inorder(child[node].second);
}

void postorder(int node) {
    if (node == -1) return;
    postorder(child[node].first);
    postorder(child[node].second);
    cout << char(node + 'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < 26; i++) {
        child[i].first = -1;
        child[i].second = -1;
    }

    for (int i = 0; i < N; i++) {
        char p, l, r; cin >> p >> l >> r;
        int pi = p - 'A';

        if (l != '.') {
            child[pi].first = l - 'A';
        }

        if (r != '.') {
            child[pi].second = r - 'A';
        }
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);

    return 0;
}