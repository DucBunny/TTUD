#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

int T, N, C;
int a[maxn];

bool canPlaceCows(int dist)
{
    int count = 1; // Place the first cow at the first position
    int lastPosition = a[0];

    for (int i = 1; i < N; i++)
    {
        if (a[i] - lastPosition >= dist)
        {
            count++;
            lastPosition = a[i];
        }
        if (count >= C)
            return true;
    }
    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> C;
        for (int i = 0; i < N; i++)
            cin >> a[i];

        sort(a, a + N);

        int low = 0, high = a[N - 1] - a[0];
        int result = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canPlaceCows(mid))
            {
                result = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        cout << result << endl;
    }

    return 0;
}
