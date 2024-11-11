// Mảng cộng dồn 2 chiều (Prefix Sum 2D Array)
// Tính tổng các phần tử từ vị trí (r1, c1) đến (r2, c2) của ma trận matrix[][].

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 1;

int n, m;
int matrix[maxN][maxN];
int prefixSum[maxN][maxN];
int Q, r1, c1, r2, c2;

void prefixSum2D()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i][j];
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];

    prefixSum2D();

    cin >> Q;
    while (Q--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << prefixSum[r2][c2] - prefixSum[r1 - 1][c2] - prefixSum[r2][c1 - 1] + prefixSum[r1 - 1][c1 - 1] << endl;
    }
}

int main()
{
    // gộp 2 vòng for trên thành 1 vòng for như sau:
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cin >> prefixSum[i][j];
    //         prefixSum[i][j] += prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
    //     }

    solve();
    return 0;
}

/* Input
3 4
1 1 0 1
1 1 1 0
0 1 0 0
3
2 3 3 4
1 3 3 4
2 2 3 4

Output
1
2
3 */