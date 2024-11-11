// Tìm đường ngắn nhất ra khỏi mê cung

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; // lưu tọa độ x, y

const int maxN = 999 + 100;

int a[maxN][maxN], m, n, r, c, d[maxN][maxN]; // r, c là vị trí xuất phát
                                              // a là mảng đánh dấu đã thăm
                                              // d là mảng đánh dấu độ dài đường đi từ điểm xuất phát đến điểm đó
                                              // m, n là kích thước của ma trận

int dx[] = {1, 0, -1, 0}, // trái, phải
    dy[] = {0, 1, 0, -1}; // lên, xuống

queue<ii> qe;

int solve()
{
    qe.push(ii(r, c));
    d[r][c] = 0;
    a[r][c] = 1;
    while (!qe.empty())
    {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (x < 1 || x > m || y < 1 || y > n) // nếu điểm đó nằm ngoài ma trận
                return d[u.first][u.second] + 1;
            if (a[x][y] != 1) // nếu điểm đó chưa được thăm
            {
                d[x][y] = d[u.first][u.second] + 1;
                qe.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> r >> c;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int ans = solve();
    cout << ans;

    return 0;
}

/* Input
8 12 5 6
1 1 0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 1 0 1 0 0 1 1
0 0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 1 0 1
1 0 0 1 0 0 0 0 0 1 0 0
1 0 1 0 1 0 0 0 1 0 1 0
0 0 0 0 1 0 1 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 0 1

Output
7 */
