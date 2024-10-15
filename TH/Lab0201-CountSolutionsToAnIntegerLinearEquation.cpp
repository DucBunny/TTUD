#include <bits/stdc++.h>
using namespace std;

int n, M, f = 0;
int a[100];
int t[100];
int X[100];
int Count = 0;

void init()
{
    t[1] = a[1];
    for (int i = 2; i <= n; i++)
        t[i] = a[i] + t[i - 1];
}

void solution()
{
    if (f == M)
        Count++;
}

void Try(int k)
{
    for (int i = 1; i < (M - f - (t[n] - t[k])) / a[k]; i++)
    {
        X[k] = i;
        f += a[i] * X[i];
        if (k < n)
            Try(k + 1);
        else
            solution();
        f -= a[k] * X[k];
    }
}

int main()
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    Try(1);
    cout << Count << endl;
}