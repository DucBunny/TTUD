// Set là một tập hợp các phần tử không trùng nhau, được sắp xếp theo thứ tự tăng dần.

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
        if (cmd.substr(0, 17) == "min_greater_equal")
        {
            int x = stoi(cmd.substr(18));
            if (s.lower_bound(x) == s.end()) // lower_bound() trả về iterator bé nhất >= x
                cout << "NULL" << endl;
            else
                cout << *s.lower_bound(x) << endl;
        }
        else if (cmd.substr(0, 11) == "min_greater")
        {
            int x = stoi(cmd.substr(12));
            if (s.upper_bound(x) == s.end()) // upper_bound() trả về iterator bé nhất > x
                cout << "NULL" << endl;
            else
                cout << *s.upper_bound(x) << endl;
        }
        else if (cmd.substr(0, 6) == "insert")
        {
            int x = stoi(cmd.substr(7));
            s.insert(x); // thêm phần tử x vào set
        }
        else if (cmd.substr(0, 6) == "remove")
        {
            int x = stoi(cmd.substr(7));
            s.erase(x); // xóa phần tử x khỏi set
        }
        else if (cmd[0] == '#')
            break;
    }

    return 0;
}