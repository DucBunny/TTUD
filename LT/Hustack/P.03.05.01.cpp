#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int oo = 1e9 + 7;

int n, K, Q, cmin = oo;
int d[N], C[N][N];
int x[N], y[N], load[N];
int segments = 0, f = 0, fOpt = oo, nbR;
bool visited[N];

void input()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> C[i][j];
            if (i != j)
                cmin = min(cmin, C[i][j]);
        }
    }
}

bool checkX(int v, int k)
{
    if (v > 0 && visited[v])
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}

void TryX(int s, int k)
{
    if (s == 0)
    {
        if (k < K)
            TryX(y[k + 1], k + 1);
        return;
    }

    for (int v = 0; v <= n; v++)
    {
        if (checkX(v, k))
        {
            x[s] = v;
            visited[v] = true;
            f += C[s, v];
            load[k] += d[v];
            segments++;
        }
    }
}

int main()
{
}