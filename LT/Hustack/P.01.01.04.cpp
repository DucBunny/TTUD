#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main()
{
    int n, x;
    cin >> n;

    while (n > 0)
    {
        cin >> x;
        s.insert(x);
        n--;
    }

    string cmd;
    while (getline(cin, cmd))
    {
        if (cmd.substr(0, 4) == "next")
        {
            int x = stoi(cmd.substr(5));
            if (s.upper_bound(x) == s.end())
                cout << -1 << endl;
            else
                cout << *s.upper_bound(x) << endl;
        }
        else if (cmd[0] == '#')
            break;
    }

    return 0;
}