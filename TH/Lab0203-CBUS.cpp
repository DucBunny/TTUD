#include <bits/stdc++.h>
using namespace std;

int n, k;
int cmin;
int load = 0; // số hành khách đã lên xe
int appear[100];
int a[100][100];
int f = 0, fbest = 0;
int x[100];

void input()
{
    scanf("%d%d", &n, &k);
    cmin = 1000000;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            scanf("%d", &a[i][j]);
            if (i != j && a[i][j] < cmin)
                cmin = a[i][j];
        }
    }
}

int check(int v, int k)
{
    if (appear[v] == 1)
        return 0;
    if (v > n)
    {
        if (!appear[v - n])
            return 0;
    }
    else
    {
        if (load + 1 > k)
            return 0;
    }
    return 1;
}

void solution()
{
    if (f + a[x[2 * n]][0] < fbest)
        fbest = f + a[x[2 * n]][0];
}

void Try(int i)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            f += a[x[k - 1]][x[k]];
            if (v <= n)
                load++;
            else
                load--;
            appear[v] = 1;
            if (i == 2 * n)
                solution();
            else
            {
                if (f + cmin * (2 * n - i + 1) < fbest)
                    Try(i + 1);
            }
            appear[v] = 0;
            if (v <= n)
                load--;
            else
                load++;
            f -= a[x[k - 1]][x[k]];
        }
    }
}

int main()
{
    input();
    Try(1);
    return 0;
}
