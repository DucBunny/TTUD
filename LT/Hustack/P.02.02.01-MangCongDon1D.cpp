// Mảng cộng dồn 1 chiều (Prefix Sum 1D Array)
// Tính tổng các phần tử từ vị trí i1 đến i2 của mảng a[].

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 1;

int n, Q, i1, i2;
long long a[maxN];
long long prefixSum[maxN];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i - 1] + a[i];

    cin >> Q;
    while (Q--)
    {
        cin >> i1 >> i2;
        cout << prefixSum[i2] - prefixSum[i1 - 1] << endl;
    }

    return 0;
}