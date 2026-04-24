#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n * 2); // safe size
    for (int i = 0; i < words.size(); i++) {
        if (!(cin >> words[i])) break;
    }

    stack<string> st;

    for (auto &w : words) {
        if (w == "") continue;

        st.push(w);

        // Try reducing
        while (st.size() >= 3) {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string t3 = st.top(); st.pop();

            if (t3 == "pair" && t2 != "pair" && t1 != "pair") {
                string combined = "pair<" + t2 + "," + t1 + ">";
                st.push(combined);
            } else {
                st.push(t3);
                st.push(t2);
                st.push(t1);
                break;
            }
        }
    }

    if (st.size() == 1 && st.top().find("pair") != string::npos || st.top() == "int") {
        cout << st.top() << endl;
    } else {
        cout << "Error occurred" << endl;
    }

    return 0;
}