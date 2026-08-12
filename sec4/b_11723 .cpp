#include <bits/stdc++.h>
using namespace std;

int n, x, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        if (s == "add") {
            cin >> x;
            m |= (1 << x);
        }
        else if (s == "remove") {
            cin >> x;
            m &= ~(1 << x);
        }
        else if (s == "check") {
            cin >> x;
            cout << ((m & (1 << x)) ? 1 : 0) << '\n';
        }
        else if (s == "toggle") {
            cin >> x;
            m ^= (1 << x);
        }
        else if (s == "all") {
            m = (1 << 21) - 1;
        }
        else if (s == "empty") {
            m = 0;
        }
    }

    return 0;
}