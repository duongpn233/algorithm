#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> t(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + 1;
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }

    cout << t[n1][n2] << endl;

    return 0;
}
