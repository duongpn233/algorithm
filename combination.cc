#include <iostream>
#include <vector>

int n, k;
std::vector<int> curSubset;

void printSubset()
{
    for (int i : curSubset)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void genSubset(int pos)
{
    int lastNum = (curSubset.empty() ? 0 : curSubset.back());
    for (int i = lastNum + 1; i <= n; i++)
    {
        curSubset.push_back(i);
        if (curSubset.size() == k)
        {
            printSubset();
        }
        else
        {
            genSubset(pos + 1);
        }
        curSubset.pop_back();
    }
}

int main()
{
    std::cin >> n >> k;
    curSubset.clear();
    genSubset(1);
    return 0;
}