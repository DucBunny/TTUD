// Tìm chiều dài đoạn dài nhất có tổng không vượt quá Q trong mảng a[].
// Sử dụng 2 con trỏ cùng chiều.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, Q;
    cin >> n >> Q;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int Longest = 0;
    int l = 0, r = 0, sum = 0;
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

    return 0;
}