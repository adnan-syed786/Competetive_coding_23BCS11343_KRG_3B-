//  leetcode question 1760. Minimum Limit of Balls in a Bag

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long checkMinimum(vector<int>& nums, int mid)
    {
        long long operations = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            operations += (nums[i] - 1) / mid;
        }

        return operations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int ans = 0;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(checkMinimum(nums, mid) <= maxOperations)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int maxOperations;
    cout << "Enter max operations: ";
    cin >> maxOperations;

    Solution obj;

    int result = obj.minimumSize(nums, maxOperations);

    cout << "Minimum possible maximum bag size: " << result << endl;

    return 0;
}