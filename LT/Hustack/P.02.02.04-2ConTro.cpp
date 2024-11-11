// Tìm chiều dài đoạn dài nhất có tổng không vượt quá Q trong mảng a[].
// Sử dụng 2 con trỏ cùng chiều.

#include <bits/stdc++.h>
using namespace std;

int n, Q;
int Longest = 0;
int l = 0, r = 0, sum = 0;

void twoPointers(int a[], int n, int Q)
{
    while (r < n)
    {
        sum += a[r];
        while (sum > Q)
        {
            sum -= a[l];
            l++;
        }
        Longest = max(Longest, r - l + 1);
        r++;
    }

    cout << Longest << endl;
}

void solve()
{
    cin >> n >> Q;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    twoPointers(a, n, Q);
}

int main()
{
    solve();
    return 0;
}

/* Input
10 40
19 2 7 6 9 1 17 19 8 4

Output
5*/