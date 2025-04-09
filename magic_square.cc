#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<vector<int>> Matrix;

vector<Matrix> allMagicSquares;

bool isMagicSquare(const Matrix &mat)
{
    int sum = mat[0][0] + mat[0][1] + mat[0][2];

    for (int i = 0; i < 3; i++)
    {
        if (mat[i][0] + mat[i][1] + mat[i][2] != sum)
            return false;
        if (mat[0][i] + mat[1][i] + mat[2][i] != sum)
            return false;
    }

    if (mat[0][0] + mat[1][1] + mat[2][2] != sum)
        return false;
    if (mat[0][2] + mat[1][1] + mat[2][0] != sum)
        return false;

    return true;
}

void generateAllMagicSquares(vector<int> &perm)
{
    do
    {
        Matrix mat = {
            {perm[0], perm[1], perm[2]},
            {perm[3], perm[4], perm[5]},
            {perm[6], perm[7], perm[8]}};
        if (isMagicSquare(mat))
            allMagicSquares.push_back(mat);
    } while (next_permutation(perm.begin(), perm.end()));
}

int calculateCost(const Matrix &A, const Matrix &B)
{
    int cost = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cost += abs(A[i][j] - B[i][j]);
    return cost;
}

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    generateAllMagicSquares(numbers);

    Matrix A = {
        {9, 3, 5},
        {1, 7, 8},
        {6, 4, 2}};

    // Matrix A = {
    //     {1, 3, 2},
    //     {4, 3, 2},
    //     {5, 4, 6}};

    int minCost = INT_MAX;
    Matrix bestMagicSquare;

    cout << allMagicSquares.size() << "\n";

    for (const auto &magic : allMagicSquares)
    {
        int cost = calculateCost(A, magic);
        if (cost < minCost)
        {
            minCost = cost;
            bestMagicSquare = magic;
        }
    }

    cout << "cost: " << minCost << "\n";

    for (const auto &row : bestMagicSquare)
    {
        for (int num : row)
            cout << num << "\t";
        cout << endl;
    }

    return 0;
}
