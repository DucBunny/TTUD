// Mảng cộng dồn 1 chiều (Prefix Sum 1D Array)
// Tính tổng các phần tử từ vị trí i1 đến i2 của mảng a[].

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 1;

int n, Q, i1, i2;
long long a[maxN];
long long prefixSum[maxN];

void prefixSum1D()
{
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i - 1] + a[i];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    prefixSum1D();

    cin >> Q;
    while (Q--)
    {
        cin >> i1 >> i2;
        cout << prefixSum[i2] - prefixSum[i1 - 1] << endl;
    }
}

int main()
{
    solve();
    return 0;
}

/* Input
5
5 8 7 1 9
4
1 2
1 5
1 3
4 5

Output
13
30
20
10 */