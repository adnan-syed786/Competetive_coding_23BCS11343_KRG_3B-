#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<string> dict;
    string s;
    dict.reserve(n * 2 + 1);

    for (int i = 0; i < n; i++) {
        cin >> s;
        dict.insert(s);
    }

    while (m--) {
        cin >> s;

        bool found = false;

        for (int i = 0; i < static_cast<int>(s.size()) && !found; i++) {
            char original = s[i];

            for (char c : {'a', 'b', 'c'}) {
                if (c == s[i]) continue;

                s[i] = c;
                if (dict.count(s)) {
                    found = true;
                    break;
                }
            }

            s[i] = original;
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}