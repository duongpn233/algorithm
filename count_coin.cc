#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int n, S;
    cin >> n >> S;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    vector<int> dp(S + 1, numeric_limits<int>::max());
    dp[0] = 0;

    for (int P = 1; P <= S; P++)
    {
        for (int x : w)
        {
            if (x <= P && dp[P - x] != numeric_limits<int>::max())
            {
                dp[P] = min(dp[P], dp[P - x] + 1);
            }
        }
    }

    for (int i = 0; i <= S; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << dp[S] << endl;

    return 0;
}
