#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long gcd(long long x, long long y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1;
        long long r = 1LL * n * min(a, b);

        long long lcm = (1LL * a * b) / gcd(a, b);

        while (l < r) {
            long long mid = l + (r - l) / 2;

            long long count = mid / a + mid / b - mid / lcm;

            if (count < n)
                l = mid + 1;
            else
                r = mid;
        }

        return l % MOD;
    }
};

int main() {
    Solution obj;

    int n, a, b;

    cout << "Enter n (which magical number): ";
    cin >> n;

    cout << "Enter a and b: ";
    cin >> a >> b;

    int result = obj.nthMagicalNumber(n, a, b);

    cout << "Nth Magical Number: " << result << endl;

    return 0;
}