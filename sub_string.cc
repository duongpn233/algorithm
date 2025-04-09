#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countSubstrings(string s)
{
    int n = s.size();
    int lastA = -1, lastB = -1, lastC = -1;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            lastA = i;
        else if (s[i] == 'b')
            lastB = i;
        else if (s[i] == 'c')
            lastC = i;

        int minPos = min({lastA, lastB, lastC});

        if (minPos >= 0)
        {
            result += minPos + 1;
        }
    }

    return result;
}

int main()
{
    cout << countSubstrings("abcbcaabc") << endl;
    return 0;
}