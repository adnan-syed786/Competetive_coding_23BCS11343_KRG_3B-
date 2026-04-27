//2141. Maximum Running Time of N Computers
#include <bits/stdc++.h>
using namespace std;

bool check(int n, vector<int>& batteries, long long mid)
{
    long long required = (long long)n * mid;
    long long totalPower = 0;

    for (int b : batteries)
    {
        totalPower += min((long long)b, mid);
    }

    return totalPower >= required;
}

long long maxRunTime(int n, vector<int>& batteries)
{
    long long left = 1;
    long long right = 0;

    for (int b : batteries)
        right += b;

    right = right / n;

    long long ans = 0;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (check(n, batteries, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, m;

    cout << "Enter number of computers: ";
    cin >> n;

    cout << "Enter number of batteries: ";
    cin >> m;

    vector<int> batteries(m);

    cout << "Enter battery capacities: ";
    for(int i = 0; i < m; i++)
    {
        cin >> batteries[i];
    }

    long long result = maxRunTime(n, batteries);

    cout << "Maximum running time for all computers: " << result << endl;

    return 0;
}