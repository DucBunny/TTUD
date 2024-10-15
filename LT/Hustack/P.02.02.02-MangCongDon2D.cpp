// Mảng cộng dồn 2 chiều (Prefix Sum 2D Array)

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 1;

int n, m;
int matrix[maxN][maxN];
int prefixSum[maxN][maxN];
int Q, r1, c1, r2, c2;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            prefixSum[i][j] += prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i][j];

    // gộp 2 vòng for trên thành 1 vòng for như sau:
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cin >> prefixSum[i][j];
    //         prefixSum[i][j] += prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
    //     }

    cin >> Q;
    while (Q--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << prefixSum[r2][c2] - prefixSum[r1 - 1][c2] - prefixSum[r2][c1 - 1] + prefixSum[r1 - 1][c1 - 1] << endl;
    }

    return 0;
}