//2897. Apply Operations on Array to Maximize Sum of Squares

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        vector<long long> cnt(31, 0);

        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if (num & (1 << b))
                    cnt[b]++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long val = 0;

            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) {
                    val |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + (val * val) % MOD) % MOD;
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;
    int result = obj.maxSum(nums, k);

    cout << "Maximum Sum of Squares: " << result << endl;

    return 0;
}