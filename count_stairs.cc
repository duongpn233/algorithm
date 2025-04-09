#include <iostream>
#include <vector>

using namespace std;

int64_t count(int n)
{
    vector<int64_t> dps(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int64_t count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (j == i)
            {
                count++;
            }
            else
            {
                count = count + dps[i - j];
            }
        }
        dps[i] = count;
    }

    return dps[n];
}

int64_t count_with_conds(int n)
{
    vector<int64_t> dps(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int64_t count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (j > 2)
            {
                break;
            }

            if (j == i)
            {
                count++;
            }
            else
            {
                count = count + dps[i - j];
            }
        }
        dps[i] = count;
    }

    return dps[n];
}

int64_t count_with_conds1(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    std::vector<int64_t> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int64_t recursive(int n)
{
    int64_t count = 0;
    if (n == 1)
    {
        return 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            count++;
        }

        count = count + recursive(n - i);
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << count(n) << endl;
    cout << recursive(n) << endl;
    return 0;
}
