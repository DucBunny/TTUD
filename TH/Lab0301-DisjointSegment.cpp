#include <bits/stdc++.h>
using namespace std;
#define maxn 100005

int n;
pair<int, int> a[maxn]; // a[i].first là điểm đầu, a[i].second là điểm cuối của đoạn

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
}

void solve()
{
    sort(a, a + n, cmp); // sắp xếp các đoạn theo thứ tự tăng dần của b
    int res = 1;         // số đoạn không giao nhau
    int last = a[0].second;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first > last)
        {
            res++;
            last = a[i].second;
        }
    }
    cout << res;
}

int main()
{
    input();
    solve();
    return 0;
}