// Range Minimum Query (RMQ) - Sparse Table
// Tìm tổng các giá trị nhỏ nhất trong các đoạn [i, j] của mảng a[].

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, i, j;
int a[N];
int M[100][N];
int res = 0;

void preprocessing()
{
    for (int i = 0; i < n; i++) // j = 0 -> M[0][i] = a[i]
        M[0][i] = a[i];

    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            M[j][i] = min(M[j - 1][i], M[j - 1][i + (1 << (j - 1))]);
}

int RMQ(int i, int j)
{
    int k = log2(j - i + 1);

    return min(M[k][i], M[k][j - (1 << k) + 1]);
}

void solve()
{
    cin >> n;
    for (int k = 0; k < n; k++)
        cin >> a[k];

    preprocessing();

    cin >> m;
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j;
        res += RMQ(i, j);
    }

    cout << res << endl;
}

int main()
{
    solve();
    return 0;
}

/* Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6 */