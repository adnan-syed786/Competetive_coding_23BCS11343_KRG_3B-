#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to build LPS array
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> search(string &pat, string &txt) {
        vector<int> lps = buildLPS(pat);
        vector<int> result;

        int i = 0; // txt pointer
        int j = 0; // pat pointer

        while (i < txt.size()) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == pat.size()) {
                result.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < txt.size() && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    string txt, pat;

    cout << "Enter text: ";
    cin >> txt;

    cout << "Enter pattern: ";
    cin >> pat;

    vector<int> result = obj.search(pat, txt);

    if (result.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}