// Kĩ thuật 2 con trỏ (Two Pointers) là một kĩ thuật giúp giảm độ phức tạp của bài toán từ O(n^2) xuống còn O(n) hoặc O(nlogn).
// Tìm số cặp số có tổng bằng M trong mảng a[].
// Sử dụng 2 con trỏ ngược chiều nhau.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, M;
    cin >> n >> M;

    int a[n];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1); // sắp xếp mảng a tăng dần

    int l = 1, r = n, res = 0; // l: con trỏ bên trái, r: con trỏ bên phải, res: số cặp số có tổng bằng M
    while (l < r)
    {
        if (a[l] + a[r] < M)
            l++;
        else if (a[l] + a[r] > M)
            r--;
        else
        {
            res++;
            l++;
            r--;
        }
    }

    cout << res << endl;

    return 0;
}